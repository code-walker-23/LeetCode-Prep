class Node{
public:
	Node* leftChild;
	Node* rightChild;

	Node(){
		leftChild = NULL;
		rightChild = NULL;
	}
};

class BitTrie{
private:
	Node* root;
public:

	BitTrie(){
		root = new Node();
	}

	void insert(int num){
		Node* temp = root;
		for(int i = 31; i >= 0; i--){
			int ithBit = (num>>i)&1;
			if(ithBit){
				if(temp->rightChild == NULL){
					temp->rightChild = new Node();
				}
				temp = temp->rightChild;
			}else{
				if(temp->leftChild == NULL){
					temp->leftChild = new Node();
				}
				temp = temp->leftChild;
			}
		}
	}

	int maxXor(int num){
		Node* temp = root;
		int optimalNum = 0;
		for(int i = 31;i >= 0; i--){
			int ithBit = (num>>i)&1;

			// desired
			if(ithBit == 0 && temp->rightChild){
				optimalNum += (1 << i);
				temp = temp->rightChild;
			}else if(ithBit == 1 && temp->leftChild){
				temp = temp->leftChild;
			}else{
				if(ithBit){
					optimalNum += (1 << i);
					temp = temp->rightChild;	
				}
				else {
					temp = temp->leftChild;
				}
			}
		}
        // we can optimal number or direct max xor calculate add (1<<i) for differ bit otherwise not
		return (num xor optimalNum);
	}
};
class Solution {
public:
   int findMaximumXOR(vector<int>& nums) {
    int n = nums.size();
    BitTrie* obj = new BitTrie();
    int maxi = 0;

    for(int i = 0; i < n; i++)obj->insert(nums[i]);

    for(int i = 0; i < n; i++){
        int maxXor = obj->maxXor(nums[i]);
        maxi = max(maxi, maxXor);
        obj->insert(nums[i]); // Insert after using it
    }

    return maxi;
}

};