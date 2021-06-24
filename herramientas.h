#ifndef HERRAMIENTAS_H_INCLUDED
#define HERRAMIENTAS_H_INCLUDED
///PROTOTIPOS
///ARTICULO
///-------------------------------------------------------///
bool agregarArticulo();

int buscarArticulo(int );

int BuscarArticuloporId(int );

int contarRegistros();

void copiarArchivoArticulo(Articulo *, int );

void mostrarVectorArticulos(Articulo *, int );

void ordenarAZArticulos(Articulo *, int );

void ordenarIDArticulos(Articulo *, int );

void ordenarPUArticulos(Articulo *, int );

void ordenarStockArticulos(Articulo *, int );

void listarArticulosOrdenados();

bool listarArticulosPorDefecto();

int listarArticulosDisponibles();

bool listarArticulosNoDisponibles();

void listarArticulos();

bool modificarPrecioU();

bool elmininarArticulo();

bool altaArticulo();

int Menuarticulos();

void seccionArticulos();
///FIN ARTICULO
///-------------------------------------------------------///
///CLIENTE
///-------------------------------------------------------///
int buscarDNICliente(int );

bool verificarCliente(int );

int agregarCliente();

int mostrarClientePorDNI(int );

int contarRegistrosClientes();

int listarClientes();

int modificarMailCliente();

int eliminarCliente();

int altaCliente();

int Menucliente();

void seccionClientes();
///FIN CLIENTE
///-------------------------------------------------------///
///VENTA
bool verificarstock(int cantidad, int idarticulo);

bool controlstock(int cantidad, int idarticulo, bool mod);

float calcularimporte(int cantidad,int idarticulo);

bool VerificarVenta(int idarticulo, int dni, int cantidad);

int buscarVenta(int Nventa);

bool agregarVenta();

int BuscarVentaporNumero(int nventa);

int contarRegistrosVentas();

bool listarVentas();

bool eliminarVenta();

bool altaVenta();

bool devolverVenta();

int Menuventas();

void seccionVenta();
///FIN VENTA
///-------------------------------------------------------///
///PROVEEDOR
bool agregarProveedor();

int buscarProveedor(int codigo);

int BuscarProveedorCod(int id);

int contarRegistrosProv();

void copiarArchivoProveedor(Proveedor *pProveeedor, int cantProveedor);

void mostrarVectorProveedor(Proveedor *pProveedor, int cantProveedor);

void ordenarAZProveedor(Proveedor *pProveeedor, int cantProveedor);

bool listarProveedorPorDefecto();

void listarProveedoresOrdenados(int orden);

void listarProveedores();

void seccionProveedores();
///FIN PROVEEDOR
///-------------------------------------------------------///
///-------------------------------------------------------///
///VENDEDOR
///-------------------------------------------------------///
int buscarDNIVendedor(int );

bool verificarVendedor(int );

int agregarVendedor();

int mostrarVendedorPorDni(int );

bool listarVendedores();

int modificarCategoria();

int eliminarVendedor();

int altaVendedor();

int menuVendedor();

void seccionVendedor();
///FIN VENDEDOR
///-------------------------------------------------------///
///CONFIGURACION
///-------------------------------------------------------///
void mostrarVentaBackup();

void mostrarVentainicial();

bool hacerBackupVentas();

bool restablecerArchivoVentas();

bool restablecerarchivosVentasinicio();
///ARCHIVO ARTICULO
void mostrarArticuloBackup();

void mostrarArticuloinicial();

bool hacerBackupArticulo();

bool restablecerArchivoArticulo();

bool restablecerarchivosArticuloinicio();
///ARCHIVOS CLIENTE
void mostrarClienteBackup();

void mostrarClienteinicial();

bool hacerBackupCliente();

bool restablecerArchivoCliente();

bool restablecerarchivosClientesinicio();

int Menuconfiguracion();

void seccionConfiguracion();
///FIN CONFIGURACION
///-------------------------------------------------------///

///GLOBALES
///-------------------------------------------------------///
void cargarCadena(char *, int );

void cartelListarArticulos();

void cartelListarProveedores();
#endif // HERRAMIENTAS_H_INCLUDED
