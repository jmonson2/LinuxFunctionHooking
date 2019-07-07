csgo_pid=$(pidof main)






input="$(
sudo gdb -n -q -batch \
  -ex "attach $csgo_pid" \
  -ex "set \$dlopen = (void*(*)(char*, int)) dlopen" \
  -ex "call \$dlopen(\"$(pwd)/bin/hijack.so\", 1)" \
  -ex "detach" \
  -ex "quit"
)"