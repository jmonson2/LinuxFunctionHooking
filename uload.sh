if grep -q libhijack.so /proc/$(pidof main)/maps; then
sudo gdb -n -q -batch \
    -ex "attach $(pidof main)" \
    -ex "set \$dlopen = (void*(*)(char*, int)) dlopen" \
    -ex "set \$dlclose = (int(*)(void*)) dlclose" \
    -ex "set \$library = \$dlopen(\"$(pwd)/libhijack.so\", 6)" \
    -ex "call \$dlclose(\$library)" \
    -ex "call \$dlclose(\$library)" \
    -ex "detach" \
    -ex "quit"
fi