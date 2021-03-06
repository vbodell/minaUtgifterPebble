AR = 'arm-none-eabi-ar'
ARFLAGS = 'rcs'
AS = 'arm-none-eabi-gcc'
BINDIR = '/usr/local/bin'
BLOCK_MESSAGE_KEYS = []
BUILD_DIR = 'aplite'
BUILD_TYPE = 'app'
BUNDLE_BIN_DIR = 'aplite'
BUNDLE_NAME = 'minaUtgifterPebble.pbw'
CC = ['arm-none-eabi-gcc']
CCLNK_SRC_F = []
CCLNK_TGT_F = ['-o']
CC_NAME = 'gcc'
CC_SRC_F = []
CC_TGT_F = ['-c', '-o']
CC_VERSION = ('4', '7', '2')
CFLAGS = ['-std=c99', '-mcpu=cortex-m3', '-mthumb', '-ffunction-sections', '-fdata-sections', '-g', '-fPIE', '-Os', '-D_TIME_H_', '-Wall', '-Wextra', '-Werror', '-Wno-unused-parameter', '-Wno-error=unused-function', '-Wno-error=unused-variable']
CFLAGS_MACBUNDLE = ['-fPIC']
CFLAGS_cshlib = ['-fPIC']
CPPPATH_ST = '-I%s'
DEFINES = ['RELEASE', 'PBL_PLATFORM_APLITE', 'PBL_BW', 'PBL_RECT', 'PBL_COMPASS', 'PBL_DISPLAY_WIDTH=144', 'PBL_DISPLAY_HEIGHT=168', 'PBL_SDK_3']
DEFINES_ST = '-D%s'
DEST_BINFMT = 'elf'
DEST_CPU = 'arm'
DEST_OS = 'darwin'
INCLUDES = ['aplite']
LD = 'arm-none-eabi-ld'
LIBDIR = '/usr/local/lib'
LIBPATH_ST = '-L%s'
LIB_DIR = 'node_modules'
LIB_JSON = []
LIB_ST = '-l%s'
LINKFLAGS = ['-mcpu=cortex-m3', '-mthumb', '-Wl,--gc-sections', '-Wl,--warn-common', '-fPIE', '-Os']
LINKFLAGS_MACBUNDLE = ['-bundle', '-undefined', 'dynamic_lookup']
LINKFLAGS_cshlib = ['-shared']
LINKFLAGS_cstlib = ['-Wl,-Bstatic']
LINK_CC = ['arm-none-eabi-gcc']
MESSAGE_KEYS = {}
MESSAGE_KEYS_HEADER = '/Users/victorbodell/terminal/git/minaUtgifterPebble/build/include/message_keys.auto.h'
NODE_PATH = '/Users/victorbodell/Library/Application Support/Pebble SDK/SDKs/current/node_modules'
PEBBLE_SDK_COMMON = '/Users/victorbodell/Library/Application Support/Pebble SDK/SDKs/current/sdk-core/pebble/common'
PEBBLE_SDK_PLATFORM = '/Users/victorbodell/Library/Application Support/Pebble SDK/SDKs/current/sdk-core/pebble/aplite'
PEBBLE_SDK_ROOT = '/Users/victorbodell/Library/Application Support/Pebble SDK/SDKs/current/sdk-core/pebble'
PLATFORM = {'TAGS': ['aplite', 'bw', 'rect', 'compass', '144w', '168h'], 'MAX_FONT_GLYPH_SIZE': 256, 'ADDITIONAL_TEXT_LINES_FOR_PEBBLE_H': [], 'MAX_APP_BINARY_SIZE': 65536, 'MAX_RESOURCES_SIZE': 524288, 'MAX_APP_MEMORY_SIZE': 24576, 'MAX_WORKER_MEMORY_SIZE': 10240, 'NAME': 'aplite', 'BUNDLE_BIN_DIR': 'aplite', 'BUILD_DIR': 'aplite', 'MAX_RESOURCES_SIZE_APPSTORE_2_X': 98304, 'MAX_RESOURCES_SIZE_APPSTORE': 131072, 'DEFINES': ['PBL_PLATFORM_APLITE', 'PBL_BW', 'PBL_RECT', 'PBL_COMPASS', 'PBL_DISPLAY_WIDTH=144', 'PBL_DISPLAY_HEIGHT=168']}
PLATFORM_NAME = 'aplite'
PREFIX = '/usr/local'
PROJECT_INFO = {'appKeys': {}, u'sdkVersion': u'3', u'projectType': u'native', u'uuid': u'2cd6e62e-9fe1-4e3d-b769-823b96b91ef2', u'messageKeys': {}, 'companyName': u'vBodell', u'enableMultiJS': True, u'targetPlatforms': [u'aplite'], 'versionLabel': u'1.0', 'longName': u'Utgifter', u'displayName': u'Utgifter', 'shortName': u'Utgifter', u'watchapp': {u'watchface': False}, u'resources': {u'media': [{u'menuIcon': True, u'type': u'png', u'name': u'WALLET_ICON', u'file': u'images/wallet.png'}, {u'targetPlatforms': None, u'type': u'bitmap', u'name': u'UP_ICON', u'file': u'images/list.png'}, {u'targetPlatforms': None, u'type': u'bitmap', u'name': u'CHECK_ICON', u'file': u'images/plus.png'}, {u'targetPlatforms': None, u'type': u'bitmap', u'name': u'DOWN_ICON', u'file': u'images/plus.png'}, {u'targetPlatforms': None, u'type': u'bitmap', u'name': u'DOWNA_ICON', u'file': u'images/down.png'}, {u'targetPlatforms': None, u'type': u'bitmap', u'name': u'UPA_ICON', u'file': u'images/up.png'}]}, 'name': u'Utgifter'}
REQUESTED_PLATFORMS = [u'aplite']
RESOURCES_JSON = [{u'menuIcon': True, u'type': u'png', u'name': u'WALLET_ICON', u'file': u'images/wallet.png'}, {u'targetPlatforms': None, u'type': u'bitmap', u'name': u'UP_ICON', u'file': u'images/list.png'}, {u'targetPlatforms': None, u'type': u'bitmap', u'name': u'CHECK_ICON', u'file': u'images/plus.png'}, {u'targetPlatforms': None, u'type': u'bitmap', u'name': u'DOWN_ICON', u'file': u'images/plus.png'}, {u'targetPlatforms': None, u'type': u'bitmap', u'name': u'DOWNA_ICON', u'file': u'images/down.png'}, {u'targetPlatforms': None, u'type': u'bitmap', u'name': u'UPA_ICON', u'file': u'images/up.png'}]
RPATH_ST = '-Wl,-rpath,%s'
SANDBOX = False
SDK_VERSION_MAJOR = 5
SDK_VERSION_MINOR = 78
SHLIB_MARKER = None
SIZE = 'arm-none-eabi-size'
SONAME_ST = '-Wl,-h,%s'
STLIBPATH_ST = '-L%s'
STLIB_MARKER = None
STLIB_ST = '-l%s'
SUPPORTED_PLATFORMS = ['aplite', 'basalt', 'chalk', 'diorite', 'emery']
TARGET_PLATFORMS = ['aplite']
TIMESTAMP = 1480285612
USE_GROUPS = True
VERBOSE = 0
WEBPACK = '/Users/victorbodell/Library/Application Support/Pebble SDK/SDKs/current/node_modules/.bin/webpack'
cprogram_PATTERN = '%s'
cshlib_PATTERN = 'lib%s.so'
cstlib_PATTERN = 'lib%s.a'
macbundle_PATTERN = '%s.bundle'
