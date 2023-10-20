//
// Created by michael.brunner on 20/10/2023.
//

#ifndef CPP_PLAYGROUND_TOBSERVER_H
#define CPP_PLAYGROUND_TOBSERVER_H

#include <functional>

template <typename Subject, typename State>
class TObserver
{
public:
	using onUpdateEvent = std::function<void(const Subject&, const State)>;

	// virtual dtor not necessary

	explicit TObserver(onUpdateEvent aOnUpdateEvent)
		: mOnUpdateEvent(std::move(aOnUpdateEvent))
	{
	}

	void update(const Subject& aSubject, const State aState)
	{
		mOnUpdateEvent(aSubject, aState);
	}

private:
	onUpdateEvent mOnUpdateEvent;

};

#endif //CPP_PLAYGROUND_TOBSERVER_H
