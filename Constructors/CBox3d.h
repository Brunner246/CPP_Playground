//
// Created by michael.brunner on 17/09/2023.
//

#ifndef CPP_PLAYGROUND_CBOX3D_H
#define CPP_PLAYGROUND_CBOX3D_H


namespace Constructors {

	class CBox3d final
	{
	public:
		CBox3d() = delete;

		CBox3d(int aWidth, int aHeight, int aDepth);

		CBox3d(const CBox3d &aOther);

		CBox3d(CBox3d &&aOther) noexcept;

		CBox3d &operator=(const CBox3d &aOther);

		CBox3d &operator=(CBox3d &&aOther) noexcept;

		~CBox3d() noexcept;

		std::string toString() const noexcept;

	private:
		int mWidth{0};

		int mHeight{0};

		int mDepth{0};

	};

} // CBox3d

#endif //CPP_PLAYGROUND_CBOX3D_H
