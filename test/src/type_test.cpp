#include <ryusei/common/defs.hpp>

using namespace std;
namespace rs = project_ryusei;

int main(int argc, char **argv)
{
  /*** Pose2D型の宣言 ***/
  rs::Pose2D pose(100.0, 100.0, CV_PI / 2.0);
  /*** LocalMap型の宣言 ***/
  rs::LocalMap map;
  /*** メンバー変数の初期化・代入等 ***/
  map.points.resize(100);
  map.pose = pose;
  /*** それぞれのインスタンスの状態表示 ***/
  cout << "Pose : " << pose << endl;
  cout << "Map : " << map << endl;

  rs::LocalMap map2;
  map2 = map;
  map2.points.resize(10);

  cout << map.points.size() << " , " << map2.points.size() << endl;
  
  return 0;
}