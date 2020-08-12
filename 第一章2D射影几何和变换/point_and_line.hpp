#ifndef POINT_AND_LINE_HPP_
#define POINT_AND_LINE_HPP_

namespace wyz_lib
{
	/***********************************************************************************************************/
	/****************************************************多视几何***********************************************/
	/***********************************************************************************************************/
	/********************************************* (x,y,z...)T为列矢量 *****************************************/
	/***********************************************************************************************************/



	/***************************************************2D射影平面**********************************************/
	// 判断一个点（x,y）是否在直线上
	// 理论：点X =（x,y）T在直线L =（a,b,c）T上的充要条件是ax + by + c = 0
	bool is_p_in_line(const double& d_p_x_, const double& d_p_y_,
					  const double& d_line_a_, const double& d_line_b_, const double& d_line_c_)
	{
		if ((d_p_x_*d_line_a_ + d_p_y_*d_line_b_ + d_line_c_) == 0)
			return true;
		else
			return false;
	}

	// 求两直线的交点
	// 理论：两直线L1 = （a1,b1,c1）和L2 = （a2,b2,c2）的交点是点X = L1 x L2
	bool is_lines_cross_return_p(const double& d_line_a1_, const double& d_line_b1_, const double& d_line_c1_,
								 const double& d_line_a2_, const double& d_line_b2_, const double& d_line_c2_,
								 double& d_p_x_, double& d_p_y_)
	{
		double d_x = d_line_b1_*d_line_c2_ - d_line_b2_*d_line_c1_;
		double d_y = d_line_c1_*d_line_a2_ - d_line_c2_*d_line_a1_;
		double d_z = d_line_a1_*d_line_b2_ - d_line_a2_*d_line_b1_;
		if (d_z == 0)
			return false;
		else
		{
			d_p_x_ = d_x / d_z;
			d_p_y_ = d_y / d_z;
			return true;
		}
	}

	// 求过已知两点（x1,y1）、(x2,y2)的直线
	// 理论：过已知两点X1 = （x1,y1）、X2 = (x2,y2)的直线L(a,b,c) = X1 x X2
	void get_line_through_two_points(const double& d_p_x1_, const double& d_p_y1_,
									 const double& d_p_x2_, const double& d_p_y2_,
									 double& d_line_a_, double& d_line_b_, double& d_line_c_)
	{
		d_line_a_ = d_p_y1_ * 1 - d_p_y2_ * 1;
		d_line_b_ = 1 * d_p_x2_ - 1 * d_p_x1_;
		d_line_c_ = d_p_x1_*d_p_y2_ - d_p_x2_*d_p_y1_;
	}
}

#endif