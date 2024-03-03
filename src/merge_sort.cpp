#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Bar {
  string color;
  int y;
};

class MergeSort {
  public:
    MergeSort(int num_bars) {
     // generate random bars between height 0 - 200
     for (int i = 0; i < num_bars; i++) {
        Bar* b = new Bar;
        b->color = "1 0 0";
        b->y = rand() % 200;
        bars.push_back(b);
     } 
    }
    
    ~MergeSort() {
      for (int i = 0; i < (int)bars.size(); i++) {
        delete bars[i];
      }
    }

    void msort(vector<Bar*>& temp, int start, int size) {
      int left, right, i;

      if (size == 1) return;
      
      if (size == 2) {
        if (bars[start]->y > bars[start+size-1]->y) {
          Bar* b = bars[start];
          bars[start] = bars[start+size-1];
          bars[start+size-1] = b;
          printBars(false);
        }
      }

      msort(temp, start, size/2);
      msort(temp, start+size/2, size-size/2);
      
      // merge
      if (size > 2) {
        left = start;
        right = start+size/2;

        while (left < size/2+start && right < size+start) {
          if (bars[left]->y <= bars[right]->y) {
            temp.push_back(bars[left]);
            left++;
          } else {
            temp.push_back(bars[right]);
            right++;
          }
       }
       
       for (i = left; i < start+size/2; i++) temp.push_back(bars[i]);
       for (i = right; i < start+size/2; i++) temp.push_back(bars[i]);
       for (i = 0; i < (int)temp.size(); i++) { 
         bars[start+i] = temp[i];
         printBars(false);
       }
       
       temp.clear();
       printBars(false);
      } 
    }
    
    void printBars(bool done) {
      string file_name = "JGRfiles/" + to_string(count) + "-ms.jgr";
      ofstream f(file_name);
      f << "newgraph" << endl;
      f << "xaxis nodraw size 5" << endl;
      f << "yaxis nodraw size 5" << endl;
      f << "newcurve marktype box cfill 0 0 0 marksize 11 60 pts 1.3 5 copygraph" << endl;  
      
      if(!done) {
        f << "newcurve marktype xbar cfill 1 0 0" << endl;
      } else {
        f << "newcurve marktype xbar cfill 0 1 0" << endl;
      }
      f << "marksize .8 5" << endl;       
      f << "pts ";
      for (int i = 0; i < (int)bars.size(); i++) {
        string s = to_string(i+1) + " " + to_string(bars[i]->y) + " ";
        f << s;
      }
      f << endl;
      count += 1;
    }
  
  private:
    vector<Bar*> bars;
    int count = 1;
};

int main(int argc, char* argv[]) {
  vector <Bar*> temp;
  
  if (argc < 2) {
    cout << "Usage: ./mergesort number_of_bars" << endl;
    return -1;
  }

  int num = stoi(argv[1]);

  MergeSort m(num);
  m.printBars(false);
  m.msort(temp, 0, num);
  m.printBars(true);
  return 0;
}
