#pragma once

#include <memory>
#include <boost/noncopyable.hpp>
#include <glm/fwd.hpp>
#include <SDL_events.h>

class CAbstractWindow : private boost::noncopyable
{
public:
	CAbstractWindow();
	virtual ~CAbstractWindow();

	void ShowFixedSize(glm::ivec2 const& size);
	void DoGameLoop();

protected:
	void SetBackgroundColor(glm::vec4 const& color);

	virtual void OnWindowEvent(const SDL_Event &event) = 0;
	virtual void OnUpdateWindow(float deltaSeconds) = 0;
	virtual void OnDrawWindow(const glm::ivec2 & size) = 0;

private:
	class Impl;
	std::unique_ptr<Impl> m_pImpl;
};