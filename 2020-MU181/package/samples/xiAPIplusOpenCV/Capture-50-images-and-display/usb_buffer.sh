#!/bin/bash
tee /sys/module/usbcore/parameters/usbfs_memory_mb >/dev/null <<<0
