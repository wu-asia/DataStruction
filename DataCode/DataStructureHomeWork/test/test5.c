// 查找员工
int Search(int id){
    int addr = Hash(id);
    int start = addr;
    while(HashTable[addr].state != 0){
        if(HashTable[addr].state == 1 && HashTable[addr].id == id){
            return addr;
        }
        addr = (addr + 1) % HASHSIZE;
        if(addr == start)       break;
    }
    return -1;
}