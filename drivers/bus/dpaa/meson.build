# SPDX-License-Identifier: BSD-3-Clause
# Copyright 2018 NXP

version = 2

if not is_linux
	build = false
	reason = 'only supported on linux'
endif

deps += ['common_dpaax', 'eventdev']
sources = files('base/fman/fman.c',
		'base/fman/fman_hw.c',
		'base/fman/netcfg_layer.c',
		'base/qbman/bman.c',
		'base/qbman/bman_driver.c',
		'base/qbman/dpaa_alloc.c',
		'base/qbman/dpaa_sys.c',
		'base/qbman/process.c',
		'base/qbman/qman.c',
		'base/qbman/qman_driver.c',
		'dpaa_bus.c')

allow_experimental_apis = true

if cc.has_argument('-Wno-cast-qual')
	cflags += '-Wno-cast-qual'
endif
if cc.has_argument('-Wno-pointer-arith')
	cflags += '-Wno-pointer-arith'
endif

includes += include_directories('include', 'base/qbman')
