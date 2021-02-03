#ifndef _RS_COMMON_DEFS_H_
#define _RS_COMMON_DEFS_H_

#include <opencv2/opencv.hpp>

namespace project_ryusei
{

/*** ロボットの位置情報(x, y, θ)を表す型 ***/
class Pose2D
{
public:
  Pose2D(){}
  Pose2D(double _x, double _y, double _yaw) : x(_x), y(_y), yaw(_yaw){}
  friend std::ostream& operator << (std::ostream &os, const Pose2D &p)
  {
    os << "[" << p.x << " , " << p.y << " , " << p.yaw * 180.0 / CV_PI << "]";
    return os;
  }
  double x = .0, y = .0, yaw = .0;
};

/*** 位置情報と点群から構成される局所的環境地図を表す型 ***/
class LocalMap
{
public:
  LocalMap(){}
  ~LocalMap(){}
  friend std::ostream& operator << (std::ostream &os, const LocalMap &lm)
  {
    os << lm.pose << " : " << lm.points.size();
    return os;
  }
  /*** 点群 ***/
  std::vector<cv::Point3f> points;
  /*** ロボット位置 ***/
  Pose2D pose;
};

/*** チームの他メンバーが使用 ***/
/*** マッチング結果に対するスコア ***/
class ScanMatchingScore
{public:
  ScanMatchingScore();
  ScanMatchingScore(double _raw, double _ref, double _que);
  friend std::ostream& operator << (std::ostream &os, const ScanMatchingScore &p)
  {
    os << "[" << p.ref << " , " << p.que << " , " << p.raw << "]";
    return os;
  }
  double ref = .0, que = .0, raw = .0;
};

/*** 障害物の位置(相対・絶対)を表す型 ***/
class Obstacle
{
public:
  Obstacle(){}
  ~Obstacle(){}
  friend std::ostream& operator << (std::ostream &os, const Obstacle &ob)
  {
    if(ob.rel.size() == 2) os << "r : " << ob.rel[0] << " , " << ob.rel[1] << std::endl;
    else if(ob.rel.size() == 4) os << "r : " << ob.rel[0] << " , " << ob.rel[1] << " , " << ob.rel[2] << " , " << ob.rel[3] << std::endl;
    else os << "r : invalid" << std::endl;
    if(ob.abs.size() == 2) os << "a : " << ob.abs[0] << " , " << ob.abs[1];
    else if(ob.abs.size() == 4) os << "a : " << ob.abs[0] << " , " << ob.abs[1] << " , " << ob.abs[2] << " , " << ob.abs[3];
    else os << "a : invalid";
    return os;
  }
  /*** 障害物の相対位置座標 ***/
  std::vector<cv::Point3f> rel;
  /*** 障害物の絶対位置座標 ***/
  std::vector<cv::Point3f> abs;
};

/*** チームの他メンバーが使用 ***/
/*** 信号の色を表す型 ***/
enum class SignalColor{
  Red = 1,
  Green = 2
};

/*** チームの他メンバーが使用 ***/
/*** 信号の画像上の位置と色を表す型 ***/
class SignalInfo{
public:
  SignalInfo(){}
  SignalInfo(SignalColor _color, const cv::Point &_pos) : color(_color), pos(_pos){}
  ~SignalInfo(){}
  friend std::ostream& operator << (std::ostream &os, const SignalInfo &info)
  {
    if(info.color == SignalColor::Red) os << "Red" << " : " << info.pos;
    else os << "Green" << " : " << info.pos;
    return os;
  }
  SignalColor color = SignalColor::Red;
  cv::Point pos;
};
}

#endif