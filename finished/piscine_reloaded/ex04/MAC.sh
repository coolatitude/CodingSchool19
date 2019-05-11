ifconfig -a link | grep "ether" | cut -c8- | rev | cut -c2- | rev
