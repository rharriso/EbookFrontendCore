#!/bin/bash
cd `dirname $0` && git submodule update --init --recursive

# build hiberlite
cd `dirname $0`/lib/hiberlite; make libhiberlite.a && cd ../../

# make into build directory
mkdir -p `dirname $0`/.build
cd `dirname $0`/.build && cmake .. && make && cd ../

# move executable to the root
cd `dirname $0` && mv `dirname $0`/.build/ebook `dirname $0`
