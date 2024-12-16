/**
 * @file ReaderWAV.cpp
 * @brief Implementation of the ReaderWAV class for reading WAV files.
 */

#include "ReaderWAV.h"
#include "WAVHeader.h"
#include <iostream>

const std::string kRED = "\033[1;31m";
const std::string kRESET = "\033[0m";
const std::string kYELLOW = "\033[33m";

/**
 * @brief Opens the WAV file for reading.
 */
void ReaderWAV::OpenWAVFile() {
    file_.open(input_file_path_, std::ios::binary);
    if (!file_.is_open()) {
        std::cerr << kRED << "Failed to open the file. Please check the file name or path and try again" << kRESET << std::endl;
        exit(2);
    }
}

/**
 * @brief Closes the WAV file.
 */
void ReaderWAV::CloseWAVFile() {
    file_.close();
}

/**
 * @brief Reads the header of the WAV file.
 */
void ReaderWAV::ReadHead() {
    WAVHeader_ = new WAVHeader;
    file_.read((char *)WAVHeader_, sizeof(WAVHeader));
}

/**
 * @brief Checks the validity of the WAV file.
 * @return True if the file is a valid WAV file, false otherwise.
 */
bool ReaderWAV::CheckingFileValidity() const {
    if (std::string((WAVHeader_->chunk_id), 4) != "RIFF" || std::string(WAVHeader_->riff_type_id, 4) != "WAVE") {
        std::cerr << kRED << "The file is not a valid WAV format!" << kRESET << std::endl;
        return false;
    } else if (!((WAVHeader_->format_tag == 1) && (WAVHeader_->num_channels == 1) &&
                 (WAVHeader_->sample_rate == 44100) && (WAVHeader_->bits_per_sample == 16))) {
        std::cerr << kRED << "This program supports only PCM, mono audio, 16 bit, sampling rate 44100!" << kRESET << std::endl;
        return false;
    } else {
        return true;
    }
}

/**
 * @brief Gets the audio samples from the WAV file.
 * @param samples The vector to store the samples.
 * @param start The start time in seconds.
 * @param end The end time in seconds.
 * @return True if samples were successfully read, false otherwise.
 */
bool ReaderWAV::GetSamples(std::vector<int16_t> &samples, uint32_t start, uint32_t end) {
    uint64_t offset = 2 * static_cast<uint64_t>(WAVHeader_->sample_rate) * static_cast<uint64_t>(start) + static_cast<uint64_t>(sizeof(WAVHeader));

    std::streampos current_pos_in_file = file_.tellg();

    if (current_pos_in_file <= offset) {
        file_.seekg(offset, std::ios::beg);

        remaining_audio_data_size_ = static_cast<uint64_t>(end - start) * static_cast<uint64_t>(WAVHeader_->sample_rate);
    }

    if (remaining_audio_data_size_ > 0) {
        size_t bytes_to_read = static_cast<uint64_t>(FIXED_SAMPLE_RATE) < remaining_audio_data_size_
                                   ? FIXED_SAMPLE_RATE
                                   : remaining_audio_data_size_;

        samples.resize(bytes_to_read);

        file_.read((char *) samples.data(), bytes_to_read * sizeof(int16_t));

        remaining_audio_data_size_ -= bytes_to_read;

        return true;
    } else {
        return false;
    }
}

/**
 * @brief Gets the WAV header of the file.
 * @return A pointer to the WAVHeader object.
 */
WAVHeader* ReaderWAV::GetWAVHeader() const {
    return WAVHeader_;
}

/**
 * @brief Gets the size of the file in seconds.
 * @return The size of the file in seconds.
 */
int ReaderWAV::GetSizeFileInSec() const {
    std::cout << this->input_file_path_ << std:: endl;
    return WAVHeader_->chunk2_data_size / (2 * WAVHeader_->sample_rate);
}
