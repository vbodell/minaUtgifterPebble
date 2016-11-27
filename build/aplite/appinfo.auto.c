#include "pebble_process_info.h"
#include "src/resource_ids.auto.h"

const PebbleProcessInfo __pbl_app_info __attribute__ ((section (".pbl_header"))) = {
  .header = "PBLAPP",
  .struct_version = { PROCESS_INFO_CURRENT_STRUCT_VERSION_MAJOR, PROCESS_INFO_CURRENT_STRUCT_VERSION_MINOR },
  .sdk_version = { PROCESS_INFO_CURRENT_SDK_VERSION_MAJOR, PROCESS_INFO_CURRENT_SDK_VERSION_MINOR },
  .process_version = { 1, 0 },
  .load_size = 0xb6b6,
  .offset = 0xb6b6b6b6,
  .crc = 0xb6b6b6b6,
  .name = "Utgifter",
  .company = "vBodell",
  .icon_resource_id = RESOURCE_ID_WALLET_ICON,
  .sym_table_addr = 0xA7A7A7A7,
  .flags = PROCESS_INFO_PLATFORM_APLITE,
  .num_reloc_entries = 0xdeadcafe,
  .uuid = { 0x2C, 0xD6, 0xE6, 0x2E, 0x9F, 0xE1, 0x4E, 0x3D, 0xB7, 0x69, 0x82, 0x3B, 0x96, 0xB9, 0x1E, 0xF2 },
  .virtual_size = 0xb6b6
};
