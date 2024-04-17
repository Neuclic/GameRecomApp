#pragma once

template<typename Key, typename Val>  //哈希表键值对
class myMap {
private:
	struct Entry {
		Key key;
		Val value;
		Entry* next; //用于碰撞检测
	};

	struct Bucket {
		Entry* head; 
		Bucket() : head(nullptr) {};
	};
	Bucket* buckets;
	size_t capacity;

public:
	myMap(size_t size) : capacity(size) {
		buckets = new Bucket[size];
	} //构造函数

	~myMap() {
		for (size_t i = 0; i < capacity; i++) {
			Entry* current = bucket[i].head;
			while (current != nullptr) {
				Entry* toDel = current;
				current = current->next;
				delete toDel;
			}
		}
		delete[] buckets;

	} //析构函数

	// 针对字符串的哈希函数
	template<>
	unsigned long SimpleMap<std::string, Game>::hash(const std::string& key) {
		unsigned long hashValue = 0;
		for (char c : key) {
			hashValue = hashValue * 31 + c;
		}
		return hashValue;
	}

	// 针对int值的哈希函数
	template<>
	unsigned long SimpleMap<int, Game>::hash(const int& key) {
		return static_cast<unsigned long>(key);
	}

	void insert(const Key& key, const Val& value) {
		unsigned long bucketIndex = hash(key) % capacity;
		Entry* newEntry = new Entry{ key, value, nullptr };

		Entry* current = buckets[bucketIndex].head;
		if (!current) {
			buckets[bucketIndex].head = newEntry;
		}
		else
		{
			while (current->next) {
				if (current->key == key) {
					//键已经存在，替换键值对即可
					current->value = value;
					delete newEntry;
					return;
				}
				current = current->next;
			}
			current->next = newEntry;
		}
	}

	value* find(const Key& key) {
		unsigned long bucketIndex = hash(key) % capacity;
		Entry* current = buckets[bucketIndex].head;

		while (current) {
			if (current->key == key) {
				return &(current->value);
			}
			current = current->next;
		}
		return nullptr;
	}
};

template<typename Key> //集合的定义
class mySet {
private:
	struct Node {
		Key key;
		Node* next;
	};

	Node* head;

public:
	mySet() : head(nullptr) {}

	~SimpleSet() {
		Node* current = head;
		while (current != nullptr) {
			Node* toDelete = current;
			current = current->next;
			delete toDelete;
		}
	}

	void insert(const Key& key) {
		if (!contains(key)) {
			Node* newNode = new Node{ key, head };
			head = newNode;
		}
	}

	bool contains(const Key& key) {
		Node* current = head;
		while (current != nullptr) {
			if (current->key == key) {
				return true;
			}
			current = current->next;
		}
		return false;
	}
};


