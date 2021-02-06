ifconfig -a | sed -n -e 's/^.ether //p' | tr -d " "
