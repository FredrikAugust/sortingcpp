#include <vector>
#include <Magick++.h>
#include <string>
#include "sorthelpers.h"

using namespace std;
using namespace Magick;

// Use imagemagick to draw an image with values of @vec
void draw_vector(vector<int> vec, string name)
{
  // let's do some drawing :)
  try
  {
    Image image(Geometry(vec.size() * 4, vec.size() * 2), Color("white"));

    image.fillColor("black");

    for (int i = 0; i < vec.size(); i++) {
      image.draw(DrawableRectangle(4 * i, vec.size() * 2 - vec[i] * 2,
                                   4 * i + 1, vec.size() * 4));
    }

    image.write("img/" + name + ".gif");
  }
  catch(exception &error_)
  {
    cout << "Caught exception: " << error_.what() << endl;
  }
}
