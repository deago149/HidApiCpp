#!/bin/bash
ag -l --cpp | entr -c -s 'make -C ./build/ && ./build/tests/RunHIDCPPTests'