#include <tchar.h>
#include "nwpwin.h"

#include <list>
#include <algorithm>

class main_window : public vsite::nwp::window
{
  std::list<POINT> points;

 protected:
	void on_paint(HDC hdc) override  
	{ 
          if (points.empty()) return;
          
		  HBRUSH blueBrush = CreateSolidBrush(RGB(0, 255, 0));
          HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		  MoveToEx(hdc, points.front().x, points.front().y, nullptr);
          std::for_each(points.begin(), points.end(),
                        [hdc](POINT p) {
                  ::Ellipse(hdc, p.x - 2, p.y - 2, p.x + 2, p.y + 2);
				  ::LineTo(hdc, p.x, p.y);
			  });

		  SelectObject(hdc, oldBrush);
          DeleteObject(blueBrush);
	}
	void on_left_button_down(POINT p) override
	{
          points.push_back(p);
          ::InvalidateRect(*this, nullptr, true);
	}
	void on_key_down(int vk) override
	{
          if (vk == VK_ESCAPE) {
            if (!points.empty()) {
              points.clear();
              ::InvalidateRect(*this, nullptr, true);
            }
          }
          if (vk == VK_BACK) {
            if (!points.empty()) {
              points.pop_back();
              ::InvalidateRect(*this, nullptr, true);
            }
          }
	}
	void on_destroy() override
	{
		::PostQuitMessage(0);
	}
};

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	vsite::nwp::application app;
	main_window w;
	w.create(0, WS_OVERLAPPEDWINDOW | WS_VISIBLE, "NWP 5");
	return app.run();
}
