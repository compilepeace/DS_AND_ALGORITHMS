

def elementsInRangeK1K2(root, k1, k2):
    if root == None:
        return
    
    if (root.data >= k1) and (root.data <= k2):
        elementsInRangeK1K2(root.left, k1, k2) 
        print(str(root.data), end = ' ')
        elementsInRangeK1K2(root.right, k1, k2)
        
    # Outside the range   
    elif root.data > k2:
        elementsInRangeK1K2(root.left, k1, k2)
        
    elif root.data < k1:
        elementsInRangeK1K2(root.right, k1, k2)
    
    pass
