//
// Created by koji on 1/1/22.
//


#ifndef FEMTO_RE_ALPHABETS_H
#define FEMTO_RE_ALPHABETS_H

#include <vector>
#include "characters.h"

class BMP {
    std::byte file_type[2] = {std::byte{'B'}, std::byte{'M'}};
    std::byte file_size[4] = { std::byte{0xfe}, std::byte{0x0a}, std::byte{0}, std::byte{0} };
    std::byte file_header_reserved[4] = {std::byte{0}, std::byte{0}, std::byte{0}, std::byte{0}};
    std::byte offset_to_date[4] = {std::byte{0x36}, std::byte{0}, std::byte{0}, std::byte{0}};

    std::byte info_header_size[4] = {std::byte{0x28}, std::byte{0}, std::byte{0}, std::byte{0}};
    std::byte height_in_pixels[4] = {std::byte{0x1e}, std::byte{0}, std::byte{0}, std::byte{0}};
    std::byte width_in_pixels[4] = {std::byte{0x1e}, std::byte{0}, std::byte{0}, std::byte{0}};

    std::vector<std::byte> width_in_pixels2(std::string str) {
        auto widht_bytes = str.length() * 30;

        std::vector<std::byte> width_in_pixeles;

        while (widht_bytes != 0) {
            unsigned char byte = widht_bytes & 0b11111111;
            width_in_pixeles.push_back(std::byte(byte));
            widht_bytes >>= 8;
        }
        if (width_in_pixeles.size() > 4) {
            throw std::runtime_error("width size must be under 4294967295 bytes: " + str);
        }
        while (width_in_pixeles.size() < 4) {
            width_in_pixeles.push_back(std::byte{0}) ;
        }
        return width_in_pixeles;
    }
    std::byte number_of_color_planes[2] = {std::byte{1}, std::byte{0}};
    std::byte number_of_bits_per_pixel[4] = {std::byte{0x18}, std::byte{0}};
    std::byte compression_method[4] = {std::byte{0}, std::byte{0}, std::byte{0}, std::byte{0}};
    std::byte image_data_size[4] = {std::byte{0xc8}, std::byte{0x0a}, std::byte{0}, std::byte{0}};
    std::byte horizontal_resolution[4] = {std::byte{1}, std::byte{0}, std::byte{0}, std::byte{0}};
    std::byte vertical_resolution[4] = {std::byte{1}, std::byte{0}, std::byte{0}, std::byte{0}};
    std::byte number_of_colors_in_palette[4] = {std::byte{0}, std::byte{0}, std::byte{0}, std::byte{0}};
    std::byte number_of_important_colors[4] = {std::byte{0}, std::byte{0}, std::byte{0}, std::byte{0}};

    unsigned long width_bytes_with_padding(std::string str) {
        auto str_len = str.length();
        auto width_bytes = 3 * 30 * str_len;
        switch (width_bytes % 4) {
            case 1:
                return width_bytes + 3;
            case 2:
                return width_bytes + 2;
            case 3:
                return width_bytes + 1;
            default:
                return width_bytes;
        }
    }

    unsigned long image_date_size_bytes(std::string str) {
        return width_bytes_with_padding(str) * 30;
    }

    std::vector<std::byte> file_size2(std::string str) {
        auto file_size_byte = image_date_size_bytes(str) + 54;
        std::vector<std::byte> file_size;

        while (file_size_byte != 0) {
            unsigned char byte = file_size_byte & 0b11111111;
            file_size.push_back(std::byte(byte));
            file_size_byte >>= 8;
        }
        if (file_size.size() > 4) {
            throw std::runtime_error("file size must be under 4294967295 bytes: " + str);
        }
        while (file_size.size() < 4) {
            file_size.push_back(std::byte{0}) ;
        }
        return file_size;
    }

    std::vector<std::byte> image_data_size2(std::string str) {
        auto image_data_size_byte = image_date_size_bytes(str);
        std::vector<std::byte> image_data_size;
        while (image_data_size_byte != 0) {
            unsigned char byte = image_data_size_byte & 0b11111111;
            image_data_size.push_back(std::byte(byte));
            image_data_size_byte >>= 8;
        }
        if (image_data_size.size() > 4) {
            throw std::runtime_error("image data size must be under 4294967295 bytes: " + str);
        }
        while (image_data_size.size() < 4) {
           image_data_size.push_back(std::byte{0}) ;
        }
        return image_data_size;
    }

public:
    void generate(std::string str) {
        std::ofstream tmp("tmp.bmp", std::ios::out | std::ios::binary | std::ios::trunc);
        for (auto e : file_type)
            tmp.put((unsigned char)e);
        for (auto e : file_size2(str))
            tmp.put((unsigned char)e);
        for (auto e : file_header_reserved)
            tmp.put((unsigned char)e);
        for (auto e : offset_to_date)
            tmp.put((unsigned char)e);
        for (auto e : info_header_size)
            tmp.put((unsigned char)e);
        for (auto e : width_in_pixels2(str))
            tmp.put((unsigned char)e);
        for (auto e : height_in_pixels)
            tmp.put((unsigned char)e);
        for (auto e : number_of_color_planes)
            tmp.put((unsigned char)e);
        for (auto e : number_of_bits_per_pixel)
            tmp.put((unsigned char)e);
        for (auto e : compression_method)
            tmp.put((unsigned char)e);
        for (auto e : image_data_size2(str))
            tmp.put((unsigned char)e);
        for (auto e : horizontal_resolution)
            tmp.put((unsigned char)e);
        for (auto e : vertical_resolution)
            tmp.put((unsigned char)e);
        for (auto e : number_of_colors_in_palette)
            tmp.put((unsigned char)e);
        for (auto e : number_of_important_colors)
            tmp.put((unsigned char)e);

        for (int i = 0; i < 30; i++) {
            for (auto c : str) {
                BitMap *bitmap;
                switch (c) {
                    case 'A':
                        bitmap = &BitMapA;
                        break;
                    case 'B':
                        bitmap = &BitMapB;
                        break;
                    case 'C':
                        bitmap = &BitMapC;
                        break;
                    default:
                        throw std::runtime_error("unsupported char" + str);
                }
                auto y = (*bitmap)[29 - i];
                for (int j = 0; j < 30; j++) {
                    if (y[j] == 0) {
                        tmp.put((unsigned)255);
                        tmp.put((unsigned)255);
                        tmp.put((unsigned)255);
                    } else {
                        tmp.put((unsigned)0);
                        tmp.put((unsigned)0);
                        tmp.put((unsigned)0);
                    }
                }
            }
            auto padding = width_bytes_with_padding(str) - str.size() * 30 * 3;
            for (int i = 0; i < padding; i++) {
                tmp.put((unsigned)0);
            }
        }
    }
};

#endif //FEMTO_RE_ALPHABETS_H
