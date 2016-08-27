#include <iostream>
using namespace std;

class HashEntry{
	private:
		int key;
		int value;
	public:
		HashEntry(int key, int value){
			this->key = key;
			this->value = value;
		}
		int getKey(){
			return key;
		}
		int getValue(){
			return value;
		}
};

class HashTable{
	private:
		HashEntry **table;
		int size;
	public:
		HashTable(int size){
			this->size = size;
			table = new HashEntry * [size];
			int i, key;
			for (i = 0; i < size; i++){
				table[i] = NULL;
			}
		}
		int getSize(){
			return size;
		}
		int get(int key){
			int hashvalue = key % size;
			while(table[hashvalue] != NULL && table[hashvalue]->getKey() != key){
				hashvalue = (hashvalue + 1) % size;
			} 
			if(table[hashvalue] == NULL){
				return -1;
			}
			else return table[hashvalue]->getValue();
		}
		void set(int key, int value){
			int hashvalue = key % size;
			while(table[hashvalue] != NULL){
				if(table[hashvalue]->getKey() != key)
					hashvalue = (hashvalue + 1) % size;
				else break;
			}
			if (table[hashvalue] != NULL){
				delete table[hashvalue];
			}
			table[hashvalue] = new HashEntry(key, value);
			return;
		}
};

int main(){
	try{ 
		HashTable *h1 = new HashTable(128);
		cout << h1->getSize();
		h1->set(245, 21);
		h1->set(128, 26);
		h1->set(300, 23);
		h1->set(129, 44);
		h1->set(140, 38);
		h1->set(130, 30);
		h1->set(95, 22);
		cout << "Checking for key 300: " << h1->get(300);
		cout << "Checking for key 128: " << h1->get(128);
	} 
    catch (exception const& ex) { 
        cerr << "Exception: " << ex.what() <<endl; 
        return -1;
    } 
}