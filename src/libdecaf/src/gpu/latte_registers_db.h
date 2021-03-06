#pragma once
#include "latte_enum_common.h"
#include "latte_enum_db.h"

#include <common/bitfield.h>
#include <cstdint>

namespace latte
{

BITFIELD(DB_ALPHA_TO_MASK, uint32_t)
   BITFIELD_ENTRY(0, 1, bool, ALPHA_TO_MASK_ENABLE)
   BITFIELD_ENTRY(8, 2, uint32_t, ALPHA_TO_MASK_OFFSET0)
   BITFIELD_ENTRY(10, 2, uint32_t, ALPHA_TO_MASK_OFFSET1)
   BITFIELD_ENTRY(12, 2, uint32_t, ALPHA_TO_MASK_OFFSET2)
   BITFIELD_ENTRY(14, 2, uint32_t, ALPHA_TO_MASK_OFFSET3)
   BITFIELD_ENTRY(16, 1, bool, OFFSET_ROUND)
BITFIELD_END

BITFIELD(DB_DEPTH_BASE, uint32_t)
   BITFIELD_ENTRY(0, 32, uint32_t, BASE_256B)
BITFIELD_END

BITFIELD(DB_DEPTH_HTILE_DATA_BASE, uint32_t)
   BITFIELD_ENTRY(0, 32, uint32_t, BASE_256B)
BITFIELD_END

BITFIELD(DB_DEPTH_INFO, uint32_t)
   BITFIELD_ENTRY(0, 3, DB_FORMAT, FORMAT)
   BITFIELD_ENTRY(3, 1, BUFFER_READ_SIZE, READ_SIZE)
   BITFIELD_ENTRY(15, 4, BUFFER_ARRAY_MODE, ARRAY_MODE)
   BITFIELD_ENTRY(25, 1, bool, TILE_SURFACE_ENABLE)
   BITFIELD_ENTRY(26, 1, bool, TILE_COMPACT)
   BITFIELD_ENTRY(31, 1, bool, ZRANGE_PRECISION)
BITFIELD_END

BITFIELD(DB_DEPTH_SIZE, uint32_t)
   BITFIELD_ENTRY(0, 10, uint32_t, PITCH_TILE_MAX)
   BITFIELD_ENTRY(10, 20, uint32_t, SLICE_TILE_MAX)
BITFIELD_END

BITFIELD(DB_DEPTH_VIEW, uint32_t)
   BITFIELD_ENTRY(0, 11, uint32_t, SLICE_START)
   BITFIELD_ENTRY(13, 11, uint32_t, SLICE_MAX)
BITFIELD_END

BITFIELD(DB_HTILE_SURFACE, uint32_t)
   BITFIELD_ENTRY(0, 1, bool, HTILE_WIDTH)
   BITFIELD_ENTRY(1, 1, bool, HTILE_HEIGHT)
   BITFIELD_ENTRY(2, 1, bool, LINEAR)
   BITFIELD_ENTRY(3, 1, bool, FULL_CACHE)
   BITFIELD_ENTRY(4, 1, bool, HTILE_USES_PRELOAD_WIN)
   BITFIELD_ENTRY(5, 1, bool, PRELOAD)
   BITFIELD_ENTRY(6, 6, uint32_t, PREFETCH_WIDTH)
   BITFIELD_ENTRY(12, 6, uint32_t, PREFETCH_HEIGHT)
BITFIELD_END

BITFIELD(DB_DEPTH_CLEAR, uint32_t)
   BITFIELD_ENTRY(0, 32, float, DEPTH_CLEAR)
BITFIELD_END

// This register controls depth and stencil tests.
BITFIELD(DB_DEPTH_CONTROL, uint32_t)
   BITFIELD_ENTRY(0, 1, bool, STENCIL_ENABLE)
   BITFIELD_ENTRY(1, 1, bool, Z_ENABLE)
   BITFIELD_ENTRY(2, 1, bool, Z_WRITE_ENABLE)
   BITFIELD_ENTRY(4, 3, REF_FUNC, ZFUNC)
   BITFIELD_ENTRY(7, 1, bool, BACKFACE_ENABLE)
   BITFIELD_ENTRY(8, 3, REF_FUNC, STENCILFUNC)
   BITFIELD_ENTRY(11, 3, DB_STENCIL_FUNC, STENCILFAIL)
   BITFIELD_ENTRY(14, 3, DB_STENCIL_FUNC, STENCILZPASS)
   BITFIELD_ENTRY(17, 3, DB_STENCIL_FUNC, STENCILZFAIL)
   BITFIELD_ENTRY(20, 3, REF_FUNC, STENCILFUNC_BF)
   BITFIELD_ENTRY(23, 3, DB_STENCIL_FUNC, STENCILFAIL_BF)
   BITFIELD_ENTRY(26, 3, DB_STENCIL_FUNC, STENCILZPASS_BF)
   BITFIELD_ENTRY(29, 3, DB_STENCIL_FUNC, STENCILZFAIL_BF)
BITFIELD_END

BITFIELD(DB_RENDER_CONTROL, uint32_t)
   BITFIELD_ENTRY(0, 1, bool, DEPTH_CLEAR_ENABLE)
   BITFIELD_ENTRY(1, 1, bool, STENCIL_CLEAR_ENABLE)
   BITFIELD_ENTRY(2, 1, bool, DEPTH_COPY)
   BITFIELD_ENTRY(3, 1, bool, STENCIL_COPY)
   BITFIELD_ENTRY(4, 1, bool, RESUMMARIZE_ENABLE)
   BITFIELD_ENTRY(5, 1, bool, STENCIL_COMPRESS_DISABLE)
   BITFIELD_ENTRY(6, 1, bool, DEPTH_COMPRESS_DISABLE)
   BITFIELD_ENTRY(7, 1, bool, COPY_CENTROID)
   BITFIELD_ENTRY(8, 3, uint8_t, COPY_SAMPLE)
   BITFIELD_ENTRY(11, 1, bool, ZPASS_INCREMENT_DISABLE)
   BITFIELD_ENTRY(12, 1, bool, COLOR_DISABLE)
   BITFIELD_ENTRY(13, 2, DB_Z_EXPORT, CONSERVATIVE_Z_EXPORT)
   BITFIELD_ENTRY(15, 1, bool, PERFECT_ZPASS_COUNTS)
BITFIELD_END

BITFIELD(DB_RENDER_OVERRIDE, uint32_t)
   BITFIELD_ENTRY(0, 2, DB_FORCE, FORCE_HIZ_ENABLE)
   BITFIELD_ENTRY(2, 2, DB_FORCE, FORCE_HIS_ENABLE0)
   BITFIELD_ENTRY(4, 2, DB_FORCE, FORCE_HIS_ENABLE1)
   BITFIELD_ENTRY(6, 1, bool, FORCE_SHADER_Z_ORDER)
   BITFIELD_ENTRY(7, 1, bool, FAST_Z_DISABLE)
   BITFIELD_ENTRY(8, 1, bool, FAST_STENCIL_DISABLE)
   BITFIELD_ENTRY(9, 1, bool, NOOP_CULL_DISABLE)
   BITFIELD_ENTRY(10, 1, bool, FORCE_COLOR_KILL)
   BITFIELD_ENTRY(11, 1, bool, FORCE_Z_READ)
   BITFIELD_ENTRY(12, 1, bool, FORCE_STENCIL_READ)
   BITFIELD_ENTRY(13, 1, DB_FORCE, FORCE_FULL_Z_RANGE)
   BITFIELD_ENTRY(15, 1, bool, FORCE_QC_SMASK_CONFLICT)
   BITFIELD_ENTRY(16, 1, bool, DISABLE_VIEWPORT_CLAMP)
   BITFIELD_ENTRY(17, 1, bool, IGNORE_SC_ZRANGE)
BITFIELD_END

BITFIELD(DB_STENCILREFMASK, uint32_t)
   BITFIELD_ENTRY(0, 8, uint32_t, STENCILREF)
   BITFIELD_ENTRY(8, 8, uint32_t, STENCILMASK)
   BITFIELD_ENTRY(16, 8, uint32_t, STENCILWRITEMASK)
BITFIELD_END

BITFIELD(DB_STENCILREFMASK_BF, uint32_t)
   BITFIELD_ENTRY(0, 8, uint32_t, STENCILREF_BF)
   BITFIELD_ENTRY(8, 8, uint32_t, STENCILMASK_BF)
   BITFIELD_ENTRY(16, 8, uint32_t, STENCILWRITEMASK_BF)
BITFIELD_END

BITFIELD(DB_PREFETCH_LIMIT, uint32_t)
   BITFIELD_ENTRY(0, 10, uint32_t, DEPTH_HEIGHT_TILE_MAX)
BITFIELD_END

BITFIELD(DB_PRELOAD_CONTROL, uint32_t)
   BITFIELD_ENTRY(0, 8, uint32_t, START_X)
   BITFIELD_ENTRY(8, 8, uint32_t, START_Y)
   BITFIELD_ENTRY(16, 8, uint32_t, MAX_X)
   BITFIELD_ENTRY(24, 8, uint32_t, MAX_Y)
BITFIELD_END

BITFIELD(DB_SHADER_CONTROL, uint32_t)
   BITFIELD_ENTRY(0, 1, bool, Z_EXPORT_ENABLE)
   BITFIELD_ENTRY(1, 1, bool, STENCIL_REF_EXPORT_ENABLE)
   BITFIELD_ENTRY(4, 2, DB_Z_ORDER, Z_ORDER)
   BITFIELD_ENTRY(6, 1, bool, KILL_ENABLE)
   BITFIELD_ENTRY(7, 1, bool, COVERAGE_TO_MASK_ENABLE)
   BITFIELD_ENTRY(8, 1, bool, MASK_EXPORT_ENABLE)
   BITFIELD_ENTRY(9, 1, bool, DUAL_EXPORT_ENABLE)
   BITFIELD_ENTRY(10, 1, bool, EXEC_ON_HIER_FAIL)
   BITFIELD_ENTRY(11, 1, bool, EXEC_ON_NOOP)
   BITFIELD_ENTRY(12, 1, bool, ALPHA_TO_MASK_DISABLE)
BITFIELD_END

BITFIELD(DB_SRESULTS_COMPARE_STATE0, uint32_t)
   BITFIELD_ENTRY(0, 3, REF_FUNC, COMPAREFUNC0)
   BITFIELD_ENTRY(4, 8, uint8_t, COMPAREVALUE0)
   BITFIELD_ENTRY(12, 8, uint8_t, COMPAREMASK0)
   BITFIELD_ENTRY(24, 1, bool, ENABLE0)
BITFIELD_END

BITFIELD(DB_SRESULTS_COMPARE_STATE1, uint32_t)
   BITFIELD_ENTRY(0, 3, REF_FUNC, COMPAREFUNC1)
   BITFIELD_ENTRY(4, 8, uint8_t, COMPAREVALUE1)
   BITFIELD_ENTRY(12, 8, uint8_t, COMPAREMASK1)
   BITFIELD_ENTRY(24, 1, bool, ENABLE1)
BITFIELD_END

BITFIELD(DB_STENCIL_CLEAR, uint32_t)
   BITFIELD_ENTRY(0, 8, uint32_t, CLEAR)
   BITFIELD_ENTRY(16, 8, uint32_t, MIN)
BITFIELD_END

} // namespace latte
