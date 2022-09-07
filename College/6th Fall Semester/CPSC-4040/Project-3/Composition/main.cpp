#include <iostream>
#include <OpenImageIO/imageio.h>
#include "Composite.h"

OIIO_NAMESPACE_USING
/* Providing A over B operation */
/* ./compose A.png B.png <optional third>*/
int main(int argc, char *argv[]) {
    Composite composite(argc,argv);
    composite.preformOperation();
    composite.outputFile();

    return 0;
}
