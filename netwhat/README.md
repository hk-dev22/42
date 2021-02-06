#### What is an IP address?

In order to understand subnets, we must quickly define IP addresses. Every device that connects to the Internet is assigned a unique IP (Internet Protocol) address, enabling data sent over the Internet to reach the right device out of the billions of devices connected to the Internet. While computers read IP addresses as binary code (a series of 1s and 0s), IP addresses are usually written as a series of alphanumeric characters.
IP Address is composed of: [ network ] [ host ]
IPv4: 32bits, IPv6: 128bits

#### What do the different parts of an IP address mean?

This section focuses on IPv4 addresses, which are presented in the form of four decimal numbers separated by periods, like 203.0.113.112. (IPv6 addresses are longer and use letters as well as numbers.)
Every IP address has two parts. The first part indicates which network the address belongs to. The second part specifies the device within that network. However, the length of the "first part" changes depending on the network's class.
Networks are categorized into different classes, labeled A through E. Class A networks can connect millions of devices. Class B networks and Class C networks are progressively smaller in size. (Class D and Class E networks are not commonly used.)
Let's break down how these classes affect IP address construction:
**Class A network**: Everything before the first period indicates the network, and everything after it specifies the device within that network. Using 203.0.113.112 as an example, the network is indicated by "203" and the device by "0.113.112."
**Class B network**: Everything before the second period indicates the network. Again using 203.0.113.112 as an example, "203.0" indicates the network and "113.112" indicates the device within that network.
**Class C network**: For Class C networks, everything before the third period indicates the network. Using the same example, "203.0.113" indicates the Class C network, and "112" indicates the device.

#### What is a subnet?

A subnet, or subnetwork, is a network inside a network. Subnets make networks more efficient. Through subnetting, network traffic can travel a shorter distance without passing through unnecessary routers to reach its destination.

Imagine Alice puts a letter in the mail that is addressed to Bob, who lives in the town right next to hers. For the letter to reach Bob as quickly as possible, it should be delivered right from Alice's post office to the post office in Bob's town, and then to Bob. If the letter is first sent to a post office hundreds of miles away, Alice's letter could take a lot longer to reach Bob.
Like the postal service, networks are more efficient when messages travel as directly as possible. When a network receives data packets from another network, it will sort and route those packets by subnet so that the packets do not take an inefficient route to their destination.

#### What is a Netmask?

A Netmask is a 32-bit "mask" used to divide an IP address into subnets and specify the network's available hosts.
255.255.255.0 is applied to the 129.144.41.101 , the result is the IPv4 address of 129.144.41.0
129.144.41.101 AND 255.255.255.0 = 129.144.41.0
In binary form, the operation is:
10000001.10010000.00101001.01100101             <== (IPv4 address)
AND
11111111.11111111.11111111.00000000             <==(netmask)

Class A, B, and C networks have default masks, also known as natural masks, as shown here:
Class A: 255.0.0.0
Class B: 255.255.0.0
Class C: 255.255.255.0

#### Why is subnetting necessary?

As the previous example illustrates, the way IP addresses are constructed makes it relatively simple for Internet routers to find the right network to route data into. However, in a Class A network (for instance), there could be millions of connected devices, and it could take some time for the data to find the right device. This is why subnetting comes in handy: subnetting narrows down the IP address to usage within a range of devices.
Because an IP address is limited to indicating the network and the device address, IP addresses cannot be used to indicate which subnet an IP packet should go to. Routers within a network use something called a subnet mask to sort data into subnetworks.

#### What is a subnet mask?

A subnet mask is like an IP address, but for only internal usage within a network. Routers use subnet masks to route data packets to the right place. Subnet masks are not indicated within data packets traversing the Internet — those packets only indicate the destination IP address, which a router will match with a subnet.
Suppose Bob answers Alice's letter, but he sends his reply to Alice's place of employment rather than her home. Alice's office is quite large with many different departments. To ensure employees receive their correspondence quickly, the administrative team at Alice's workplace sorts mail by department rather than by individual employee. After receiving Bob's letter, they look up Alice's department and see she works in Customer Support. They send the letter to the Customer Support department instead of to Alice, and the customer support department gives it to Alice.
In this analogy, "Alice" is like an IP address and "Customer Support" is like a subnet mask. By matching Alice to her department, Bob's letter was quickly sorted into the right group of potential recipients. Without this step, office administrators would have to spend time laboriously looking for the exact location of Alice's desk, which could be anywhere in the building.
For a real-world example, suppose an IP packet is addressed to the IP address 192.0.2.15. This IP address is a Class C network, so the network is identified by "192.0.2" (or to be technically precise, 192.0.2.0/24). Network routers forward the packet to a host on the network indicated by "192.0.2."
Once the packet arrives at that network, a router within the network consults its routing table. It does some binary mathematics using its subnet mask of 255.255.255.0, sees the device address "15" (the rest of the IP address indicates the network), and calculates which subnet the packet should go to. It forwards the packet to the router or switch responsible for delivering packets within that subnet, and the packet arrives at IP address 192.0.2.15 .
What is the subnet of an IP with Netmask
It is called a subnet mask because it is used to identify network address of an IP address by perfoming a bitwise AND operation on the netmask.
        <network> <subnet> <host>
Every single computer that is connected to a subnet shares an identical portion of the IP address.

**Reserved address ranges for private (non-routed) use:**
    • 10.0.0.0 -> 10.255.255.255
    • 172.16.0.0 -> 172.31.255.255
    • 192.168.0.0 -> 192.168.255.255

Counting out the bits in the binary conversion allows you to determine the netmask length

#### What is the broadcast address of a subnet?

Highest IP address in a subnet or network, used as the destination IP address for broadcast messages.
In 255.255.255.255, the final "255" is the assigned broadcast address.

Number of hosts:
2^(32-n) – 2, n=netmask length

#### What is TCP?

TCP (Transmision Control Protocol) Main protocols of the internet protol suite.
    • Keeps track of lost packages, makes sure that lost packages are re-sent
    • Addes sequesce numbers to packets and reorders any packets that arrive in thenworng order.
    • Slower, because of all added additional functionality.
    • Requieres more computer resources, because the OS needs to keep track of ongoing communication sessions and manage them on a much deeper level.

#### What is UDP?

​    • Doesn't keep track of lost packages
​    • Doesn't care about package arrival order.
​    • Faster, bacause it lacks any extra features.
​    • Requieres less computer resources.
​    • Examples of programs and services that use UPD:
​        ◦ DNS
​        ◦ IP telephony
​        ◦ DHCP
​        ◦ Many computer games

#### Why we use UDP?

Many applications that requiere real-time communication prefer to use UDP, applications that requiere speed and that torerat partial data loss.

#### What are the network layers?

In the seven-layer OSI model of computer network, the network layer is layer 3. The network layer is responsible for packet forwarding including routing through intermediate routers.

#### What is the OSI model?

The Open System Interconnection (OSI). It has been developed by ISO - 'International Organization of Standardization'. It is a 7 layer architecture with each layer having specific functionality to perform. All tese 7 layers work collaboratively to transmit the data fr4om one person to another across the globe.
Layer
Kind
Application Layer
software layer
Presentatation layer
software layer
Session Layer
software layer
Transport Layer
Heart of OSI
Network Layer
hardware Layer
Data Link Layer
hardware Layer
Physical layer
hardware Layer

#### What is a DHCP server and the DHCP protocol?

DHCP server: DHCP (Dynamic Host Confivguration Protocol), is a protocol that provides quick, automatic, and central management for the distribution of IP addresses within a network. DHCP is also used to configure the subnet mask, default gateway and DNS server information on the device.

#### What is a DNS server and the DNS protocol?

Domain Name System (DNS) is the phonebook of internet. Web browsers interact through Internet Protocol (IP) addresses. DNS translates domain names to IP addresses so browsers can load internet resources.
The Domain Network System (DNS) protocol helps internet users and network devises discover websites using human-readable hostnames, instead of numeric IP addresses.
What are the rules to make 2 devices communicate using IP addresses?

#### How does routing work with IP?

​    • Routing is the process by which data packets move from one node (machine or device) to another on a computer network until the packets reach the final destination.
The header information includes:
​    • The IP addresses of the source and destination nodes.
​    • Packet numbers that help reassemble the packets in the correct order whe the packets reach the destination.
​    • Other useful technical information.

#### What is a default gateway for routing?

It allows devices within one network to send information to devises within another network. If you are requestiong a certain web page, the trafic is first sent to your default gateay before leaving the local network to reach its indended destination.

#### What is a port from an IP point of view and what is it used for when connecting?

In computer networking, a port is a communication endpoint. At the software level, within an operating system, a port is a logical construct that identifies a specific process or a type of network service. Ports are identified for each protocol and address combination by 16-bit unsigned numbers, commonly known as the port number. The most common protocols that use port numbers are the Transmission Control Protocol (TCP) and the User Datagram Protocol (UDP).