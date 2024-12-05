#include <iostream>

using namespace std;

struct Node {
  int lh, rh;
  int best;
  Node *left;
  Node *right;

  Node(int lh_, int rh_)
      : lh(lh_), rh(rh_), best(rh_ - lh_), left(nullptr), right(nullptr) {}
};

int insert(Node *root, int x) {
  if (root->left == nullptr) {
    root->left = new Node(root->lh, x);
    root->right = new Node(x, root->rh);
    root->best = max(x - root->lh, root->rh - x);
  } else {
    if (x < root->left->rh) {
      insert(root->left, x);
    } else {
      insert(root->right, x);
    }
    root->best = max(root->left->best, root->right->best);
  }

  return root->best;
}

int main(void) {
  int n, x;
  cin >> x >> n;

  Node *root = new Node(0, x);
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    cout << insert(root, k) << " ";
  }

  return 0;
}
