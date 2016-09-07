#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct TaoBaoItem {
  int price;
  int volume_of_sales;
};

bool CompareByPrice(TaoBaoItem a, TaoBaoItem b) {
	return a.price > b.price;
}
bool CompareBySales(TaoBaoItem a, TaoBaoItem b) {
	return a.volume_of_sales > b.volume_of_sales;
}

class SortInterface {
public:
	virtual ~SortInterface() {};
	virtual void DoSort(TaoBaoItem item[], int size) = 0;
};
class SortByPrice: public SortInterface {
public:
	virtual void DoSort(TaoBaoItem item[], int size) {
		sort(item, item + size, CompareByPrice);
	}
};
class SortBySales: public SortInterface {
public:
	virtual void DoSort(TaoBaoItem item[], int size) {
		sort(item, item + size, CompareBySales);
	}
};

class TaoBao {
public:
	TaoBao(SortInterface* strategy) {
		strategy_ = strategy;
	}
	void SetSortStrategy(SortInterface* strategy) {
		strategy_ = strategy;
	}
	void sort(TaoBaoItem item[], int size) {
		strategy_->DoSort(item, size);
	}
private:
	SortInterface* strategy_;
};

void printItem(TaoBaoItem arr[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << arr[i].price << " " << arr[i].volume_of_sales << endl;
  }
}

int main(int argc, char *argv[]) {
  TaoBaoItem item[4] = {
    {1, 2},
    {2, 3},
    {5, 1},
    {3, 10}
  };
  SortByPrice price;
  SortBySales sales;

  TaoBao taobao(&price); 
  taobao.sort(item, 4);
  printItem(item, 4);
  
  taobao.SetSortStrategy(&sales);
  taobao.sort(item, 4);
  printItem(item, 4);

  return 0;
}
