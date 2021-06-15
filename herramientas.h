#ifndef HERRAMIENTAS_H_INCLUDED
#define HERRAMIENTAS_H_INCLUDED




///PROTOTIPOS
void cargarCadena(char *pal, int tam);
///ARTICULO
///-------------------------------------------------------///
bool agregarArticulo();

int buscarArticulo(int codigo);

int BuscarArticuloporId(int id);

int contarRegistros();

bool listarArticulos();

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

int agregarCliente();

int mostrarClientePorDNI(int );

int contarRegistrosClientes();

int listarClientes();

int modificarMail();

int eliminarCliente();

int altaCliente();

int Menucliente();

void seccionClientes();



///FIN CLIENTE
///-------------------------------------------------------///
///VENTA
bool verificarstock(int cantidad, int idarticulo);

bool controlstock(int cantidad, int idarticulo, bool mod);

int calcularimporte(int cantidad,int idarticulo);

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
///CONFIGURACION
///-------------------------------------------------------///
void mostrarVentaBackup();

void mostrarVentainicial();

bool hacerBackupVentas();

bool restablecerArchivoVentas();

bool restablecerarchivosVentasinicio();
///-------------------------------------------------------///
///ARCHIVO ARTICULO
///-------------------------------------------------------///
void mostrarArticuloBackup();

void mostrarArticuloinicial();

bool hacerBackupArticulo();

bool restablecerArchivoArticulo();

bool restablecerarchivosArticuloinicio();
///-------------------------------------------------------///
///ARCHIVOS CLIENTE
///-------------------------------------------------------///
void mostrarClienteBackup();

void mostrarClienteinicial();

bool hacerBackupCliente();

bool restablecerArchivoCliente();

bool restablecerarchivosClientesinicio();

int Menuconfiguracion();

void seccionConfiguracion();
///FIN CONFIGURACION
///-------------------------------------------------------///


#endif // HERRAMIENTAS_H_INCLUDED
