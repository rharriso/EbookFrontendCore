# make into build directory
mkdir -p `dirname $0`/.build
cd `dirname $0`/.build && cmake .. && make && cd ../

# move executable to the root
cd `dirname $0` && mv `dirname $0`/.build/ebook `dirname $0`
