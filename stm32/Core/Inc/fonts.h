#ifndef INC_FONTS_H_
#define INC_FONTS_H_

#define SMALL_FONT_WIDTH 4
#define SMALL_FONT_HIEGHT 8

const uint8_t font_small[96][4] = {
  {0x00, 0x00, 0x00, 0x00}, /// 32 space
  {0x2e, 0x00, 0x00, 0x00}, /// 33 !
  {0x06, 0x00, 0x06, 0x00}, /// 34 "
  {0x3e, 0x14, 0x3e, 0x14}, /// 35 #
  {0x2c, 0x66, 0x34, 0x00}, /// 36 $
  {0x32, 0x08, 0x26, 0x00}, /// 37 %
  {0x6c, 0x5a, 0x36, 0x40}, /// 38 &
  {0x06, 0x00, 0x00, 0x00}, /// 39 '
  {0x00, 0x1c, 0x22, 0x00}, /// 40 (
  {0x22, 0x1c, 0x00, 0x00}, /// 41 )
  {0x0a, 0x04, 0x0a, 0x00}, /// 42 *
  {0x08, 0x1c, 0x08, 0x00}, /// 43 +
  {0x20, 0x10, 0x00, 0x00}, /// 44 ,
  {0x08, 0x08, 0x08, 0x00}, /// 45 -
  {0x20, 0x00, 0x00, 0x00}, /// 46 .
  {0x30, 0x08, 0x06, 0x00}, /// 47 /
  {0x1c, 0x22, 0x1c, 0x00}, /// 48 0
  {0x24, 0x3e, 0x20, 0x00}, /// 49 1
  {0x32, 0x2a, 0x24, 0x00}, /// 50 2
  {0x2a, 0x2a, 0x3e, 0x00}, /// 51 3
  {0x0e, 0x08, 0x3e, 0x00}, /// 52 4
  {0x2e, 0x2a, 0x12, 0x00}, /// 53 5
  {0x3e, 0x2a, 0x3a, 0x00}, /// 54 6
  {0x32, 0x0a, 0x06, 0x00}, /// 55 7
  {0x36, 0x2a, 0x36, 0x00}, /// 56 8
  {0x0e, 0x0a, 0x3e, 0x00}, /// 57 9
  {0x14, 0x00, 0x00, 0x00}, /// 58 :
  {0x34, 0x00, 0x00, 0x00}, /// 59 ;
  {0x08, 0x14, 0x22, 0x00}, /// 60 <
  {0x14, 0x14, 0x14, 0x00}, /// 61 =
  {0x22, 0x14, 0x08, 0x00}, /// 62 >
  {0x02, 0x2a, 0x06, 0x00}, /// 63 ?
  {0x1c, 0x14, 0x3c, 0x10}, /// 64 @
  {0x3e, 0x0a, 0x3e, 0x00}, /// 65 A
  {0x3e, 0x2a, 0x1c, 0x00}, /// 66 B
  {0x3e, 0x22, 0x22, 0x00}, /// 67 C
  {0x3e, 0x22, 0x1c, 0x00}, /// 68 D
  {0x3e, 0x2a, 0x22, 0x00}, /// 69 E
  {0x3e, 0x0a, 0x02, 0x00}, /// 70 F
  {0x3e, 0x22, 0x3a, 0x00}, /// 71 G
  {0x3e, 0x08, 0x3e, 0x00}, /// 72 H
  {0x22, 0x3e, 0x22, 0x00}, /// 73 I
  {0x22, 0x3e, 0x02, 0x00}, /// 74 J
  {0x3e, 0x08, 0x36, 0x00}, /// 75 K
  {0x3e, 0x20, 0x20, 0x00}, /// 76 L
  {0x3e, 0x04, 0x3e, 0x00}, /// 77 M
  {0x3e, 0x02, 0x3e, 0x00}, /// 78 N
  {0x3e, 0x22, 0x3e, 0x00}, /// 79 O
  {0x3e, 0x0a, 0x0e, 0x00}, /// 80 P
  {0x1e, 0x12, 0x3e, 0x00}, /// 81 Q
  {0x3e, 0x12, 0x2c, 0x00}, /// 82 R
  {0x24, 0x2a, 0x12, 0x00}, /// 83 S
  {0x02, 0x3e, 0x02, 0x00}, /// 84 T
  {0x3e, 0x20, 0x3e, 0x00}, /// 85 U
  {0x1e, 0x20, 0x1e, 0x00}, /// 86 V
  {0x3e, 0x10, 0x3e, 0x00}, /// 87 W
  {0x36, 0x08, 0x36, 0x00}, /// 88 X
  {0x0e, 0x38, 0x0e, 0x00}, /// 89 Y
  {0x32, 0x2a, 0x26, 0x00}, /// 90 Z
  {0x00, 0x3e, 0x22, 0x00}, /// 91 [
  {0x06, 0x08, 0x30, 0x00}, /// 92 \ backslash
  {0x22, 0x3e, 0x00, 0x00}, /// 93 ]
  {0x04, 0x02, 0x04, 0x00}, /// 94 ^
  {0x20, 0x20, 0x20, 0x00}, /// 95 _
  {0x02, 0x04, 0x00, 0x00}, /// 96 `
  {0x3e, 0x0a, 0x3e, 0x00}, /// 97 A
  {0x3e, 0x2a, 0x1c, 0x00}, /// 98 B
  {0x3e, 0x22, 0x22, 0x00}, /// 99 C
  {0x3e, 0x22, 0x1c, 0x00}, /// 100 D
  {0x3e, 0x2a, 0x22, 0x00}, /// 101 E
  {0x3e, 0x0a, 0x02, 0x00}, /// 102 F
  {0x3e, 0x22, 0x3a, 0x00}, /// 103 G
  {0x3e, 0x08, 0x3e, 0x00}, /// 104 H
  {0x22, 0x3e, 0x22, 0x00}, /// 105 I
  {0x22, 0x3e, 0x02, 0x00}, /// 106 J
  {0x3e, 0x08, 0x36, 0x00}, /// 107 K
  {0x3e, 0x20, 0x20, 0x00}, /// 108 L
  {0x3e, 0x04, 0x3e, 0x00}, /// 109 M
  {0x3e, 0x02, 0x3e, 0x00}, /// 110 N
  {0x3e, 0x22, 0x3e, 0x00}, /// 111 O
  {0x3e, 0x0a, 0x0e, 0x00}, /// 112 P
  {0x1e, 0x12, 0x3e, 0x00}, /// 113 Q
  {0x3e, 0x12, 0x2c, 0x00}, /// 114 R
  {0x24, 0x2a, 0x12, 0x00}, /// 115 S
  {0x02, 0x3e, 0x02, 0x00}, /// 116 T
  {0x3e, 0x20, 0x3e, 0x00}, /// 117 U
  {0x1e, 0x20, 0x1e, 0x00}, /// 118 V
  {0x3e, 0x10, 0x3e, 0x00}, /// 119 W
  {0x36, 0x08, 0x36, 0x00}, /// 120 X
  {0x0e, 0x38, 0x0e, 0x00}, /// 121 Y
  {0x32, 0x2a, 0x26, 0x00}, /// 122 Z
  {0x08, 0x1c, 0x22, 0x00}, /// 123 {
  {0x00, 0x3e, 0x00, 0x00}, /// 124 |
  {0x22, 0x1c, 0x08, 0x00}, /// 125 }
  {0x04, 0x02, 0x04, 0x02}, /// 126 ~
  {0x00, 0x00, 0x00, 0x00}  /// 127 blank
};

#endif /* INC_FONTS_H_ */
