#include <cstdio>
#include <cstdint>


uint32_t my_ntohl(uint32_t n) {
	printf("0x%x\n",n);
    return (n & 0x000000FF) << 24 | (n & 0x0000FF00) << 8 | (n & 0x00FF0000) >> 8 | (n & 0xFF000000) >> 24;
}


int main(int argc, char * argv[]){
	
	FILE *fp, *fp2;
	uint8_t network_buf[4];
    uint8_t network_buf2[4];

	fp = fopen(argv[1],"rb");
	fp2 = fopen(argv[2],"rb");

	
	fread(network_buf,sizeof(uint8_t),4,fp);
	fread(network_buf2,sizeof(uint8_t),4,fp2);

	uint32_t* p = reinterpret_cast<uint32_t*>(network_buf);
	uint32_t value1 = my_ntohl(*p);
	
	uint32_t* p2 = reinterpret_cast<uint32_t*>(network_buf2);
	uint32_t value2 = my_ntohl(*p2);

	uint32_t value3 = value1 + value2;
		
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",value1,value1,value2,value2,value3,value3);
	
	return 0;

}
