#pragma once

#include <switch.h>

typedef union {
  u32 color_abgr;

  struct {
    u8 r, g, b, a;
  };

} color_t;

typedef enum {
    IMAGE_MODE_RGB24,
    IMAGE_MODE_RGBA32,
    IMAGE_MODE_BGR24,
    IMAGE_MODE_ABGR32
} ImageMode;

typedef enum {
  ALIGNED_LEFT,
  ALIGNED_CENTER,
  ALIGNED_RIGHT
} TextAlignment;

typedef struct {
    u8 magic[4]; // 'fFNT'
    int version; // 1
    u16 npages;
    u8 height;
    u8 baseline;
} ffnt_header_t;

typedef struct {
    u32 size, offset;
} ffnt_pageentry_t;

typedef struct {
    u32 pos[0x100];
    u8 widths[0x100];
    u8 heights[0x100];
    int8_t advances[0x100];
    int8_t posX[0x100];
    int8_t posY[0x100];
} ffnt_pagehdr_t;

typedef struct {
    ffnt_pagehdr_t hdr;
    u8 data[];
} ffnt_page_t;

typedef struct {
    u8 width, height;
    int8_t posX, posY, advance;
    const u8* data;
} glyph_t;
