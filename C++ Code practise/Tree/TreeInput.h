/*every node stors the address of its children*/

#include<vector>
using namespace std;
template <typename T>

class TreeNode{
    public:
    T data;
    vector<TreeNode *> children; /*very node will ahve a vector that will store the address children*/
};