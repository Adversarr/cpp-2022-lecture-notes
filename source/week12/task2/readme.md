题干没有说明的问题：

```cpp
void main()
{	
  CMatrix m1(3,5);
	for(int i=0; i<m1.row; i++)
		for(int j=0; j<m1.col; j++)
			m1.AddElem( i*j, i, j);
             m1.show();
	
	CMatrix m2;
  m2=m1.inverse();
	m2.show();

	m2.set(1, 1, 100);
	m2.set(2, 3, 100);
	m2.show();

	m2=m2.inverse();
	CMatrix m3=m1+m2;
	m3.show();
}
```

set 和 AddElem 的信息并不明确：

1. 在`m2=m1.inverse()`后，显然m2是一个5x3的矩阵，那么set(2, 3, 100)访问的实际上是二维数组中`[1][2]`位置。
2. AddElem函数访问内部二维数组时却直接访问实际位置。

所以在实现上统一了一下，功能基本不变。

