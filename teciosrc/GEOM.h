 #if defined EXTERN
 #undef EXTERN
 #endif
 #if defined ___1616
 #define EXTERN
 #else
 #define EXTERN extern
 #endif
struct ___1519;
 #define VALID_RECTANGLE_COORDSYS(___3921) (((___3921) == CoordSys_Frame) || ((___3921) == CoordSys_Grid))
 #define VALID_SQUARE_COORDSYS(___3921)    VALID_RECTANGLE_COORDSYS((___3921))
 #define VALID_ELLIPSE_COORDSYS(___3921)   VALID_RECTANGLE_COORDSYS((___3921))
 #define VALID_CIRCLE_COORDSYS(___3921)    VALID_ELLIPSE_COORDSYS((___3921))
 #define VALID_IMAGE_COORDSYS(___3921)     (VALID_RECTANGLE_COORDSYS((___3921) || ___3921 == CoordSys_Grid3D))
 #define VALID_LINESEG_COORDSYS(___3921)   (((___3921) == CoordSys_Frame) || ((___3921) == CoordSys_Grid) || ((___3921) == CoordSys_Grid3D))
 #define VALID_GEOM_COORDSYS(___3921)      (((___3921) == CoordSys_Frame) || ((___3921) == CoordSys_Grid) || ((___3921) == CoordSys_Grid3D))
 #define GEOM_USES_V3(___1553) (___1553->___3168 == CoordSys_Grid3D && ___1553->___1651 == GeomType_LineSegs)
 #define VALID_GEOM_TYPE(___1649) (VALID_ENUM((___1649), GeomType_e) && (___1649) != GeomType_LineSegs3D)
 #define VALID_GEOM_FIELD_DATA_TYPE(___904) (((___904) == FieldDataType_Float) || ((___904) == FieldDataType_Double))
