typedef struct treeNode * position;
typedef position tree;

struct treeNode
{
	int value;
	int lm;
	int rm;
	position left;
	position right;
};

static int max = -1; //store the max dist
//define tree node 


//get the max deep distance of tree recursively

int maxdist(tree root)
{
	if(root == NULL)
		return 0;
	if(root->left != NULL)
		root->lm = maxdist(root->left)+1;
	if (root->right != NULL)
		root->rm = maxdist(root->right)+1;

	int sum = root->lm + root->rm;
	if(sum > max)
		max = sum;

	return root->lm > root->rm ? root->lm : root->rm;
}