class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1  # New node is initially added at leaf, hence height is 1

class AVLTree:
    def get_height(self, node):
        if not node:
            return 0
        return node.height

    def get_balance(self, node):
        if not node:
            return 0
        return self.get_height(node.left) - self.get_height(node.right)

    def left_rotate(self, z):
        y = z.right
        T2 = y.left

        # Perform rotation
        y.left = z
        z.right = T2

        # Update heights
        z.height = 1 + max(self.get_height(z.left), self.get_height(z.right))
        y.height = 1 + max(self.get_height(y.left), self.get_height(y.right))

        # Return new root
        return y

    def right_rotate(self, z):
        y = z.left
        T3 = y.right

        # Perform rotation
        y.right = z
        z.left = T3

        # Update heights
        z.height = 1 + max(self.get_height(z.left), self.get_height(z.right))
        y.height = 1 + max(self.get_height(y.left), self.get_height(y.right))

        # Return new root
        return y

    def insert(self, node, key):
        # 1. Perform the normal BST insertion
        if not node:
            return Node(key)
        elif key < node.key:
            node.left = self.insert(node.left, key)
        else:
            node.right = self.insert(node.right, key)

        # 2. Update the height of this ancestor node
        node.height = 1 + max(self.get_height(node.left), self.get_height(node.right))

        # 3. Get the balance factor
        balance = self.get_balance(node)

        # 4. If the node becomes unbalanced, then we need to rotate it

        # Left Left Case
        if balance > 1 and key < node.left.key:
            return self.right_rotate(node)

        # Right Right Case
        if balance < -1 and key > node.right.key:
            return self.left_rotate(node)

        # Left Right Case
        if balance > 1 and key > node.left.key:
            node.left = self.left_rotate(node.left)
            return self.right_rotate(node)

        # Right Left Case
        if balance < -1 and key < node.right.key:
            node.right = self.right_rotate(node.right)
            return self.left_rotate(node)

        # Return the (unchanged) node pointer
        return node

    def min_value_node(self, node):
        if node is None or node.left is None:
            return node
        return self.min_value_node(node.left)

    def delete(self, root, key):
        # 1. Perform the normal BST delete
        if not root:
            return root
        elif key < root.key:
            root.left = self.delete(root.left, key)
        elif key > root.key:
            root.right = self.delete(root.right, key)
        else:
            # Node with only one child or no child
            if root.left is None:
                temp = root.right
                root = None
                return temp
            elif root.right is None:
                temp = root.left
                root = None
                return temp

            # Node with two children: Get the inorder successor
            temp = self.min_value_node(root.right)

            # Copy the inorder successor's content to this node
            root.key = temp.key

            # Delete the inorder successor
            root.right = self.delete(root.right, temp.key)

        # If the tree had only one node then return
        if root is None:
            return root

        # 2. Update the height of the current node
        root.height = 1 + max(self.get_height(root.left), self.get_height(root.right))

        # 3. Get the balance factor
        balance = self.get_balance(root)

        # 4. If the node becomes unbalanced, then balance it

        # Left Left Case
        if balance > 1 and self.get_balance(root.left) >= 0:
            return self.right_rotate(root)

        # Left Right Case
        if balance > 1 and self.get_balance(root.left) < 0:
            root.left = self.left_rotate(root.left)
            return self.right_rotate(root)

        # Right Right Case
        if balance < -1 and self.get_balance(root.right) <= 0:
            return self.left_rotate(root)

        # Right Left Case
        if balance < -1 and self.get_balance(root.right) > 0:
            root.right = self.right_rotate(root.right)
            return self.left_rotate(root)

        return root

    # A utility function to print the preorder traversal of the tree
    def pre_order(self, node):
        if not node:
            return
        print(f"{node.key} ", end="")
        self.pre_order(node.left)
        self.pre_order(node.right)


# Example usage of AVL Tree
if __name__ == "__main__":
    tree = AVLTree()
    root = None

    # Insert nodes into the tree
    keys = [10, 20, 30, 40, 50, 25]

    for key in keys:
        root = tree.insert(root, key)

    # Preorder traversal of the constructed AVL tree
    print("Preorder traversal of the AVL tree is:")
    tree.pre_order(root)
    print()

    # Deleting a node
    root = tree.delete(root, 40)

    # Preorder traversal after deletion
    print("Preorder traversal after deletion of 40:")
    tree.pre_order(root)
    print()
