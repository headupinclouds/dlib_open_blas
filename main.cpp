#include <dlib/geometry/point_transforms.h>

int gauze_main(int argc, char *argv[])
{
    using fpoint = dlib::vector<float, 2>;
    using PointVecf = std::vector<fpoint>;    
    const dlib::rectangle rect(0,0,128,96 );
    PointVecf to_points{ rect.tl_corner(), rect.tr_corner(), rect.br_corner() };
    PointVecf from_points{ { 0, 0 }, { 1, 0 }, { 1, 1 } };

    // Note that BEFORE/AFTER are buffered in gauze tests
    // via cmake's execute_process() so we won't actually
    // see IO until the process completes.  If it hangs we
    // won't see anything in the terminal.
    std::cout << "BEFORE" << std::endl;
        
    // Comment this line to void the hang
    dlib::find_affine_transform(from_points, to_points);

    // We won't see "AFTER" until the hang is addressed
    std::cout << "AFTER" << std::endl;    
    
    return 0;
}
