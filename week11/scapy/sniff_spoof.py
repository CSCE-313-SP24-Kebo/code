
from scapy.all import * # get allmthe definitions fomr scapy


print("SNIFFING AND SPOOFING PACKETS.........")

# This function modifies any ICMP packet
def spoof_pkt(pkt):
    if ICMP in pkt and pkt[ICMP].type == 8:
        print("===Original Packet===")
        print("Source IP: ", pkt[IP].src)
        print("Destination IP:", pkt[IP].dst, "\n")

        # Spoofed data (Stack)
        a = IP(src=pkt[IP].dst, dst=pkt[IP].src, ihl=pkt[IP].ihl) # Modification
        b = ICMP(type=0, id=pkt[ICMP].id, seq=pkt[ICMP].seq)
        data = pkt[Raw].load

        # create a new tampered stack
        spoof = a/b/data


        #######
        print("===Spoofed Packet===")
        print("Source IP: ", spoof[IP].src)
        print("Destination IP:", spoof[IP].dst, "\n")

        send(spoof, verbose=0)
        # sendp(spoof, iface ="....")


#pkt = sniff(iface='ens4', filter='icmp', prn=spoof_pkt)
def main():
    pkt = sniff(filter='icmp', prn=spoof_pkt)

main()
