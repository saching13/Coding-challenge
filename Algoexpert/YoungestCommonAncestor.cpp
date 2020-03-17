#include <vector>
using namespace std;

class AncestralTree {
public:
  char name;
  AncestralTree *ancestor;

  AncestralTree(char name) {
    this->name = name;
    this->ancestor = NULL;
  }

  void addAsAncestor(vector<AncestralTree *> descendants);
	
	
	
};
// User implemented
void getAncstor(AncestralTree *CurrDescendent, vector<AncestralTree *>& ancestorList){
		if(CurrDescendent->ancestor == NULL){
			ancestorList.push_back(CurrDescendent);
		}
		else{
			getAncstor(CurrDescendent->ancestor,ancestorList);
			ancestorList.push_back(CurrDescendent);
		}
		return;	
	}
// User implemented
AncestralTree *getYoungestCommonAncestor(AncestralTree *topAncestor,
                                         AncestralTree *descendantOne,
                                         AncestralTree *descendantTwo) {
	int len;
	AncestralTree *result;
	vector<AncestralTree *> ancestorOne;
	vector<AncestralTree *> ancestorTwo;
    
	getAncstor(descendantOne,ancestorOne);
	getAncstor(descendantTwo,ancestorTwo);
	
	if(ancestorOne.size() > ancestorTwo.size()) len = ancestorTwo.size();
	else len = ancestorOne.size();
	
	for(int i = 0; i < len; i++){
		if(ancestorOne[i]->name == ancestorTwo[i] -> name) result = ancestorOne[i];
		else break;
	}
	
  // Write your code here.
  return result;
}
