//sort
//1.1 insert sort  1.2shell sort  
// too easy

//2.1 bubble sort  
// too easy

//2.2 quick sort
void quickSort(int a[],int left,int right) {
 if (left >= right) return;
 int i=left, j=right, base=a[left];
 while (i < j) {
  if (i < j && a[j] >= base) j--;
  if (i < j && a[i] <= base) i++;
  if (i < j) {
   swap(a[i], a[j]); 
  }
 }
 
 a[left] = a[i];
 a[i] = base;
 
 quickSort(a, left, i - 1);
 quickSort(a, i + 1, right);
}
//3.1 selection sort  
// too easy

//3.2 heap sort
void sift(vector<int>& a, int root, int length) {
  int parent = root, child = parent*2;
  while(child<length) {
    if (a[child+1]>a[child]) child = child + 1;
    
    if (a[child]>a[parent]) swap(a[child], a[parent]);
    else break;
    
    parent = child, child = parent*2;
  }
}
 
void heapSort(vector<int> & a, int len) {
	for (int i = len / 2; i >= 0; i--) {
		sift(a,i,len);
	}
  
	for (int j = len - 1; j > 0; j--) {
    swap(a[0], a[j]);
		sift(nums,0,j);
	}
}

//4 merge sort
vector<int> mergeSort(vector<int>& nums, int l, int r) {
  if (l > r) return {};
  if (l == r) return {nums[l]};
  int m = l + (r - l) / 2;
  
  auto ln = mergeSort(nums, l, m);
  auto rn = mergeSort(nums, m + 1, r);
  
  vector<int> res;
  int i = 0，j = 0;
  while (i < ln.size() && j < rn.size()) {
    if (ln[i] <= rn[j]) {
      res.push_back(ln[i++]);
    } else {
      res.push_back(rn[j++]);
    }
  }
  
  while (i < ln.size()) res.push_back(ln[i++]);
  while (j < rn.size()) res.push_back(rn[j++]);
  
  return res;
}

//5 redix sort
// too easy
