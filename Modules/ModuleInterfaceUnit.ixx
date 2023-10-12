//
// Created by michael.brunner on 12/10/2023.
//



module;

export module math;

import <vector>;
import <numeric>;


export namespace math {

	int add(int fir, int sec)
	{
		return fir + sec;
	}

	int getProduct(const std::vector<int> &vec)
	{
		return std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<>());
	}

}
