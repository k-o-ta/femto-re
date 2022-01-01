#include <iostream>
#include <fstream>
#include "femto-re.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    BMP bmp;
    bmp.generate(BitMapA);
//
    return 0;


    std::ofstream tmp("tmp.bmp", std::ios::out | std::ios::binary | std::ios::trunc);
//    tmp.open("tmp.txt", std::ios::out);
//    std::byte a{255};
    std::byte by{0b000'0001};
//    tmp.write((char *)a, 0);
//    tmp.put((unsigned char)a);
//    tmp.write((char *)a, sizeof(std::byte));
    unsigned char a('a');
    unsigned char b('b');
    unsigned char c(1);
    std::byte file_type[] = {
            std::byte{'B'},
            std::byte{'M'}
    };
//    std::byte file_header[] = {
//            std::byte{2}
//    };
//    unsigned char file_type[] = {'B', 'M' };
//    unsigned char file_header_reserved[] = { 0, 0, 0, 0, 0, 0, 0, 0};
    std::byte file_header_reserved[] = { std::byte{0},std::byte{0},std::byte{0},std::byte{0}};
//    unsigned char offset_to_data[] = { 36, 0, 0, 0 };
    std::byte offset_to_date[] = { std::byte{0x36},std::byte{0},std::byte{0},std::byte{0}};
//    char abc[] = {1, 2, 3};
//    unsigned char abc[] = {1, 2, 3};
//    tmp.put(a);
    std::cout << "tmpfile!" << std::endl;
//    tmp << a << b << c;
//    tmp << abc;
//    tmp << file_type;
    for (auto e : file_type)
        tmp.put((unsigned char)e);
    // file size
    for (auto e : { std::byte{0x16},std::byte{0x2f},std::byte{0},std::byte{0} })
        tmp.put((unsigned)e);
//    for (auto e : { std::byte{0xe6},std::byte{0x04},std::byte{0},std::byte{0} })
    for (auto e : file_header_reserved)
        tmp.put((unsigned char)e);
    for (auto e : offset_to_date)
        tmp.put((unsigned char)e);

    // 情報ヘッダのサイズ
    for (auto e : { std::byte{0x28}, std::byte{0},std::byte{0},std::byte{0} })
        tmp.put((unsigned)e);
    // 画像の幅
    for (auto e : { std::byte{0x14}, std::byte{0},std::byte{0},std::byte{0} })
        tmp.put((unsigned)e);
    // 画像の高さ
    for (auto e : { std::byte{0x14}, std::byte{0},std::byte{0},std::byte{0} })
        tmp.put((unsigned)e);
    // プレーン数
    for (auto e : { std::byte{0x1},std::byte{0} })
        tmp.put((unsigned)e);
    // 1画像あたりの色数
    for (auto e : { std::byte{0x18},std::byte{0} })
        tmp.put((unsigned)e);
    // 圧縮形式
    for (auto e : { std::byte{0},std::byte{0},std::byte{0},std::byte{0} })
        tmp.put((unsigned)e);
    // 画像データのサイズ
//    for (auto e : { std::byte{0xb0},std::byte{0x04},std::byte{0},std::byte{0} })
    for (auto e : { std::byte{0xe0},std::byte{0x2e},std::byte{0},std::byte{0} })
        tmp.put((unsigned)e);
    // 水平解像度
    for (auto e : { std::byte{1},std::byte{0},std::byte{0},std::byte{0} })
        tmp.put((unsigned)e);
    // 垂直解像度
    for (auto e : { std::byte{1},std::byte{0},std::byte{0},std::byte{0} })
        tmp.put((unsigned)e);
    // パレットの色数
    for (auto e : { std::byte{0},std::byte{0},std::byte{0},std::byte{0} })
        tmp.put((unsigned)e);
    // 重要パレットのindex
    for (auto e : { std::byte{0},std::byte{0},std::byte{0},std::byte{0} })
        tmp.put((unsigned)e);
//    for (auto e : { std::byte{0},std::byte{0},std::byte{0},std::byte{0} })
//        tmp.put((unsigned)e);


    // データ
    for (auto e : {
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{100},std::byte{100},std::byte{100},
            std::byte{100},std::byte{100},std::byte{100}
    })
        tmp.put((unsigned)e);
    for (auto e : {
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{100},std::byte{100},std::byte{100},
            std::byte{100},std::byte{100},std::byte{100}
    })
        tmp.put((unsigned)e);
    for (auto e : {
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{100},std::byte{100},std::byte{100},
            std::byte{100},std::byte{100},std::byte{100}
    })
        tmp.put((unsigned)e);
    for (auto e : {
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{100},std::byte{100},std::byte{100},
            std::byte{100},std::byte{100},std::byte{100}
    })
        tmp.put((unsigned)e);
    for (auto e : {
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{100},std::byte{100},std::byte{100},
            std::byte{100},std::byte{100},std::byte{100}
    })
        tmp.put((unsigned)e);
    for (auto e : {
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{100},std::byte{100},std::byte{100},
            std::byte{100},std::byte{100},std::byte{100}
    })
        tmp.put((unsigned)e);
    for (auto e : {
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{100},std::byte{100},std::byte{100},
            std::byte{100},std::byte{100},std::byte{100}
    })
        tmp.put((unsigned)e);
    for (auto e : {
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{100},std::byte{100},std::byte{100},
            std::byte{100},std::byte{100},std::byte{100}
    })
        tmp.put((unsigned)e);
    for (auto e : {
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{100},std::byte{100},std::byte{100},
            std::byte{100},std::byte{100},std::byte{100}
    })
        tmp.put((unsigned)e);
    for (auto e : {
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{100},std::byte{100},std::byte{100},
            std::byte{100},std::byte{100},std::byte{100}
    })
        tmp.put((unsigned)e);
    for (auto e : {
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{100},std::byte{100},std::byte{100},
            std::byte{100},std::byte{100},std::byte{100}
    })
        tmp.put((unsigned)e);
    for (auto e : {
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{100},std::byte{100},std::byte{100},
            std::byte{100},std::byte{100},std::byte{100}
    })
        tmp.put((unsigned)e);
    for (auto e : {
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{100},std::byte{100},std::byte{100},
            std::byte{100},std::byte{100},std::byte{100}
    })
        tmp.put((unsigned)e);
    for (auto e : {
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{100},std::byte{100},std::byte{100},
            std::byte{100},std::byte{100},std::byte{100}
    })
        tmp.put((unsigned)e);
    for (auto e : {
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{100},std::byte{100},std::byte{100},
            std::byte{100},std::byte{100},std::byte{100}
    })
        tmp.put((unsigned)e);
    for (auto e : {
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{100},std::byte{100},std::byte{100},
            std::byte{100},std::byte{100},std::byte{100}
    })
        tmp.put((unsigned)e);
    for (auto e : {
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{100},std::byte{100},std::byte{100},
            std::byte{100},std::byte{100},std::byte{100}
    })
        tmp.put((unsigned)e);
    for (auto e : {
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{255},std::byte{255},std::byte{255},
            std::byte{100},std::byte{100},std::byte{100},
            std::byte{100},std::byte{100},std::byte{100}
    })
        tmp.put((unsigned)e);
    for (auto e : {
        std::byte{255},std::byte{255},std::byte{255},
        std::byte{255},std::byte{255},std::byte{255},
        std::byte{255},std::byte{255},std::byte{255},
        std::byte{255},std::byte{255},std::byte{255},
        std::byte{255},std::byte{255},std::byte{255},
        std::byte{255},std::byte{255},std::byte{255},
        std::byte{255},std::byte{255},std::byte{255},
        std::byte{255},std::byte{255},std::byte{255},
        std::byte{255},std::byte{255},std::byte{255},
        std::byte{255},std::byte{255},std::byte{255},
        std::byte{255},std::byte{255},std::byte{255},
        std::byte{255},std::byte{255},std::byte{255},
        std::byte{255},std::byte{255},std::byte{255},
        std::byte{255},std::byte{255},std::byte{255},
        std::byte{255},std::byte{255},std::byte{255},
        std::byte{255},std::byte{255},std::byte{255},
        std::byte{255},std::byte{255},std::byte{255},
        std::byte{255},std::byte{255},std::byte{255},
        std::byte{100},std::byte{100},std::byte{100},
        std::byte{100},std::byte{100},std::byte{100}
    })
        tmp.put((unsigned)e);
    for (auto e : {
        std::byte{0},std::byte{0},std::byte{0},
        std::byte{0},std::byte{0},std::byte{0},
        std::byte{0},std::byte{0},std::byte{0},
        std::byte{0},std::byte{0},std::byte{0},
        std::byte{0},std::byte{0},std::byte{0},
        std::byte{0},std::byte{0},std::byte{0},
        std::byte{0},std::byte{0},std::byte{0},
        std::byte{0},std::byte{0},std::byte{0},
        std::byte{0},std::byte{0},std::byte{0},
        std::byte{0},std::byte{0},std::byte{0},
        std::byte{0},std::byte{0},std::byte{0},
        std::byte{0},std::byte{0},std::byte{0},
        std::byte{0},std::byte{0},std::byte{0},
        std::byte{0},std::byte{0},std::byte{0},
        std::byte{0},std::byte{0},std::byte{0},
        std::byte{0},std::byte{0},std::byte{0},
        std::byte{0},std::byte{0},std::byte{0},
        std::byte{0},std::byte{0},std::byte{0},
        std::byte{0},std::byte{0},std::byte{0},
        std::byte{0},std::byte{0},std::byte{0}
    })
        tmp.put((unsigned)e);

    return 0;
}
