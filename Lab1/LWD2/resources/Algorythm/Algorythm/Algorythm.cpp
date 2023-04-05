#include <iostream>
#include <vector>

class Good
{
public:
	std::string name;
	std::string field1;
	std::string field2;
	std::string field3;
private:
};

std::vector<Good> Goods;
std::vector<std::vector<Good>> Goods_Collection;
std::vector<Good> a;
std::vector<Good> b;
std::vector<Good> c;


int main()
{
	Good item_1, item_2, item_3, item_4, item_5, item_6;
	item_1.name = "a";
	item_1.field2 = "1";
	item_2.name = "b";
	item_2.field2 = "3";
	item_3.name = "c";
	item_3.field2 = "5";
	item_4.name = "a";
	item_4.field2 = "2";
	item_5.name = "b";
	item_5.field2 = "4";
	item_6.name = "c";
	item_6.field2 = "6";
	Goods.insert(Goods.end(), { item_1, item_2, item_3, item_4, item_5, item_6 });
	for (auto it : Goods)
	{
		if (it.name == "a")
			a.push_back(it);
		if (it.name == "b")
			b.push_back(it);
		if (it.name == "c")
			c.push_back(it);
	}
	for (auto it_a : a)
	{
		for (auto it_b : b)
		{
			for (auto it_c : c)
			{
				std::cout << it_a.field2 << it_b.field2 << it_c.field2 << '\n';
			}
		}
		}
	

}