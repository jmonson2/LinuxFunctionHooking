main_pid=$(pidof main)






input="$(
sudo gdb -n -q -batch \
  -ex "attach $main_pid" \
  -ex "set \$dlopen = (void*(*)(char*, int)) dlopen" \
  -ex "call \$dlopen(\"$(pwd)/bin/libhijack.so\", 1)" \
  -ex "detach" \
  -ex "quit"
)"