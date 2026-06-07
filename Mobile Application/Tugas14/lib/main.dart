import 'package:flutter/material.dart';
import 'package:flutter_map/flutter_map.dart';
import 'package:latlong2/latlong.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Tugas 14 - Maps',
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        useMaterial3: true,
        colorScheme: ColorScheme.fromSeed(
          seedColor: const Color(0xFF6366F1), // Elegant Indigo
          brightness: Brightness.light,
        ),
      ),
      darkTheme: ThemeData(
        useMaterial3: true,
        colorScheme: ColorScheme.fromSeed(
          seedColor: const Color(0xFF6366F1), // Elegant Indigo
          brightness: Brightness.dark,
        ),
      ),
      themeMode: ThemeMode.system,
      home: const MapScreen(),
    );
  }
}

class MapScreen extends StatefulWidget {
  const MapScreen({super.key});

  @override
  State<MapScreen> createState() => _MapScreenState();
}

class _MapScreenState extends State<MapScreen> with SingleTickerProviderStateMixin {
  final MapController _mapController = MapController();
  
  // Coordinates
  static const LatLng _telkomUniv = LatLng(-6.974001, 107.630348);
  static const LatLng _gedungSate = LatLng(-6.902481, 107.618765);
  
  bool _isAtGedungSate = false;
  late List<Marker> _markers;
  
  // Details for the active place info card
  String _placeTitle = "Telkom University";
  String _placeSubtitle = "Kampus Teknologi Utama";
  String _placeDescription = "Universitas swasta terkemuka di Bandung yang berfokus pada teknologi, informasi, dan sains. Kampus ini memiliki area hijau yang luas dan modern, terletak di Dayeuhkolot.";
  String _placeCoords = "-6.974001, 107.630348";
  IconData _placeIcon = Icons.school;
  Color _placeThemeColor = Colors.redAccent;

  @override
  void initState() {
    super.initState();
    // Initialize with just the Telkom University marker
    _markers = [
      _buildMarker(_telkomUniv, "Telkom Univ", Colors.redAccent, Icons.school),
    ];
  }
  
  // Builder function to create a custom marker with a pulsing dot and label
  Marker _buildMarker(LatLng point, String label, Color color, IconData icon) {
    return Marker(
      point: point,
      width: 100,
      height: 90,
      child: GestureDetector(
        onTap: () => _selectMarker(label),
        child: Column(
          mainAxisSize: MainAxisSize.min,
          children: [
            // Text Label
            Container(
              padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 4),
              decoration: BoxDecoration(
                color: Colors.white,
                borderRadius: BorderRadius.circular(8),
                border: Border.all(color: color.withOpacity(0.5), width: 1),
                boxShadow: [
                  BoxShadow(
                    color: Colors.black.withOpacity(0.15),
                    blurRadius: 4,
                    offset: const Offset(0, 2),
                  ),
                ],
              ),
              child: Text(
                label,
                style: const TextStyle(
                  fontSize: 10,
                  fontWeight: FontWeight.bold,
                  color: Colors.black87,
                ),
              ),
            ),
            const SizedBox(height: 4),
            // Pin Icon with pulsing background
            Stack(
              alignment: Alignment.center,
              children: [
                _PulseCircle(color: color),
                Icon(
                  Icons.location_on,
                  color: color,
                  size: 38,
                ),
                Positioned(
                  top: 7,
                  child: Icon(
                    icon,
                    color: Colors.white,
                    size: 14,
                  ),
                ),
              ],
            ),
          ],
        ),
      ),
    );
  }

  // Smooth camera movements with custom AnimationController
  void _animatedMapMove(LatLng destLocation, double destZoom) {
    final latTween = Tween<double>(
        begin: _mapController.camera.center.latitude, end: destLocation.latitude);
    final lngTween = Tween<double>(
        begin: _mapController.camera.center.longitude, end: destLocation.longitude);
    final zoomTween = Tween<double>(
        begin: _mapController.camera.zoom, end: destZoom);

    final controller = AnimationController(
        duration: const Duration(milliseconds: 1500), vsync: this);
    final animation = CurvedAnimation(parent: controller, curve: Curves.fastOutSlowIn);

    controller.addListener(() {
      _mapController.move(
        LatLng(latTween.evaluate(animation), lngTween.evaluate(animation)),
        zoomTween.evaluate(animation),
      );
    });

    animation.addStatusListener((status) {
      if (status == AnimationStatus.completed || status == AnimationStatus.dismissed) {
        controller.dispose();
      }
    });

    controller.forward();
  }

  // Action executed when the Floating Action Button is clicked
  void _toggleLocation() {
    setState(() {
      _isAtGedungSate = !_isAtGedungSate;
      
      if (_isAtGedungSate) {
        // Add Gedung Sate marker if it is not already in the list
        if (_markers.length < 2) {
          _markers.add(_buildMarker(_gedungSate, "Gedung Sate", Colors.teal, Icons.museum));
        }
        
        _placeTitle = "Gedung Sate";
        _placeSubtitle = "Ikon Bersejarah Kota Bandung";
        _placeDescription = "Gedung bersejarah dengan arsitektur Neo-Klasik yang berpadu dengan unsur tradisional Sunda. Dibangun pada tahun 1920, saat ini berfungsi sebagai gedung pusat pemerintahan Jawa Barat.";
        _placeCoords = "-6.902481, 107.618765";
        _placeIcon = Icons.museum;
        _placeThemeColor = Colors.teal;
        
        _animatedMapMove(_gedungSate, 15.5);
      } else {
        _placeTitle = "Telkom University";
        _placeSubtitle = "Kampus Teknologi Utama";
        _placeDescription = "Universitas swasta terkemuka di Bandung yang berfokus pada teknologi, informasi, dan sains. Kampus ini memiliki area hijau yang luas dan modern, terletak di Dayeuhkolot.";
        _placeCoords = "-6.974001, 107.630348";
        _placeIcon = Icons.school;
        _placeThemeColor = Colors.redAccent;
        
        _animatedMapMove(_telkomUniv, 15.5);
      }
    });
  }

  // Handle manual selection when tapping on markers
  void _selectMarker(String label) {
    setState(() {
      if (label == "Telkom Univ") {
        _isAtGedungSate = false;
        _placeTitle = "Telkom University";
        _placeSubtitle = "Kampus Teknologi Utama";
        _placeDescription = "Universitas swasta terkemuka di Bandung yang berfokus pada teknologi, informasi, dan sains. Kampus ini memiliki area hijau yang luas dan modern, terletak di Dayeuhkolot.";
        _placeCoords = "-6.974001, 107.630348";
        _placeIcon = Icons.school;
        _placeThemeColor = Colors.redAccent;
        _animatedMapMove(_telkomUniv, 15.5);
      } else if (label == "Gedung Sate") {
        _isAtGedungSate = true;
        _placeTitle = "Gedung Sate";
        _placeSubtitle = "Ikon Bersejarah Kota Bandung";
        _placeDescription = "Gedung bersejarah dengan arsitektur Neo-Klasik yang berpadu dengan unsur tradisional Sunda. Dibangun pada tahun 1920, saat ini berfungsi sebagai gedung pusat pemerintahan Jawa Barat.";
        _placeCoords = "-6.902481, 107.618765";
        _placeIcon = Icons.museum;
        _placeThemeColor = Colors.teal;
        _animatedMapMove(_gedungSate, 15.5);
      }
    });
  }

  @override
  Widget build(BuildContext context) {
    final theme = Theme.of(context);
    final isDark = theme.brightness == Brightness.dark;

    return Scaffold(
      body: Stack(
        children: [
          // OpenStreetMap Tile and Marker Layer
          FlutterMap(
            mapController: _mapController,
            options: MapOptions(
              initialCenter: _telkomUniv,
              initialZoom: 15.5,
              maxZoom: 18,
              minZoom: 10,
            ),
            children: [
              TileLayer(
                urlTemplate: 'https://tile.openstreetmap.org/{z}/{x}/{y}.png',
                userAgentPackageName: 'com.college.task.tugas14_maps',
                // Custom color matrix to create a sleek dark map theme if system is dark
                tileBuilder: isDark 
                  ? (context, tileWidget, tile) {
                      return ColorFiltered(
                        colorFilter: const ColorFilter.matrix([
                          -0.2126, -0.7152, -0.0722,  0, 255,
                          -0.2126, -0.7152, -0.0722,  0, 255,
                          -0.2126, -0.7152, -0.0722,  0, 255,
                            0,       0,       0,      1,   0,
                        ]),
                        child: tileWidget,
                      );
                    }
                  : null,
              ),
              MarkerLayer(
                markers: _markers,
              ),
            ],
          ),

          // Translucent Header Panel
          Positioned(
            top: MediaQuery.of(context).padding.top + 16,
            left: 16,
            right: 16,
            child: Container(
              padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 12),
              decoration: BoxDecoration(
                color: (isDark ? Colors.grey[900] ?? Colors.black : Colors.white).withOpacity(0.85),
                borderRadius: BorderRadius.circular(16),
                border: Border.all(
                  color: (isDark ? Colors.white : Colors.black).withOpacity(0.1),
                ),
                boxShadow: [
                  BoxShadow(
                    color: Colors.black.withOpacity(0.1),
                    blurRadius: 10,
                    offset: const Offset(0, 4),
                  ),
                ],
              ),
              child: Row(
                children: [
                  Container(
                    padding: const EdgeInsets.all(8),
                    decoration: BoxDecoration(
                      color: theme.colorScheme.primary.withOpacity(0.15),
                      shape: BoxShape.circle,
                    ),
                    child: Icon(
                      Icons.map_rounded,
                      color: theme.colorScheme.primary,
                    ),
                  ),
                  const SizedBox(width: 12),
                  Expanded(
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      mainAxisSize: MainAxisSize.min,
                      children: [
                        const Text(
                          "Bandung Map Explorer",
                          style: TextStyle(
                            fontSize: 16,
                            fontWeight: FontWeight.bold,
                            letterSpacing: 0.5,
                          ),
                        ),
                        Text(
                          "Tugas 14: Implementasi Fitur Maps",
                          style: TextStyle(
                            fontSize: 11,
                            color: isDark ? Colors.grey[400] : Colors.grey[600],
                          ),
                        ),
                      ],
                    ),
                  ),
                ],
              ),
            ),
          ),

          // Dynamic Info Card displaying current place details
          Positioned(
            bottom: MediaQuery.of(context).padding.bottom + 90,
            left: 16,
            right: 16,
            child: AnimatedSwitcher(
              duration: const Duration(milliseconds: 300),
              transitionBuilder: (child, animation) {
                return FadeTransition(
                  opacity: animation,
                  child: SlideTransition(
                    position: Tween<Offset>(
                      begin: const Offset(0, 0.1),
                      end: Offset.zero,
                    ).animate(animation),
                    child: child,
                  ),
                );
              },
              child: Container(
                key: ValueKey<String>(_placeTitle),
                padding: const EdgeInsets.all(16),
                decoration: BoxDecoration(
                  color: (isDark ? const Color(0xFF1E1E1E) : Colors.white).withOpacity(0.9),
                  borderRadius: BorderRadius.circular(20),
                  border: Border.all(
                    color: (isDark ? Colors.white : Colors.black).withOpacity(0.15),
                  ),
                  boxShadow: [
                    BoxShadow(
                      color: Colors.black.withOpacity(0.15),
                      blurRadius: 15,
                      offset: const Offset(0, 5),
                    ),
                  ],
                ),
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  mainAxisSize: MainAxisSize.min,
                  children: [
                    Row(
                      children: [
                        Container(
                          padding: const EdgeInsets.all(10),
                          decoration: BoxDecoration(
                            color: _placeThemeColor.withOpacity(0.15),
                            borderRadius: BorderRadius.circular(12),
                          ),
                          child: Icon(
                            _placeIcon,
                            color: _placeThemeColor,
                            size: 24,
                          ),
                        ),
                        const SizedBox(width: 12),
                        Expanded(
                          child: Column(
                            crossAxisAlignment: CrossAxisAlignment.start,
                            children: [
                              Text(
                                _placeTitle,
                                style: const TextStyle(
                                  fontSize: 18,
                                  fontWeight: FontWeight.bold,
                                ),
                              ),
                              Text(
                                _placeSubtitle,
                                style: TextStyle(
                                  fontSize: 13,
                                  color: _placeThemeColor,
                                  fontWeight: FontWeight.w600,
                                ),
                              ),
                            ],
                          ),
                        ),
                      ],
                    ),
                    const Divider(height: 24, thickness: 0.5),
                    Text(
                      _placeDescription,
                      style: TextStyle(
                        fontSize: 13,
                        color: isDark ? Colors.grey[300] : Colors.grey[700],
                        height: 1.4,
                      ),
                    ),
                    const SizedBox(height: 12),
                    Row(
                      children: [
                        Icon(
                          Icons.location_on_outlined,
                          size: 14,
                          color: isDark ? Colors.grey[400] : Colors.grey[600],
                        ),
                        const SizedBox(width: 4),
                        Text(
                          _placeCoords,
                          style: TextStyle(
                            fontSize: 11,
                            fontFamily: 'monospace',
                            color: isDark ? Colors.grey[400] : Colors.grey[600],
                          ),
                        ),
                        const Spacer(),
                        // Allows user to manually switch details via text actions
                        TextButton.icon(
                          onPressed: () => _selectMarker(_isAtGedungSate ? "Telkom Univ" : "Gedung Sate"),
                          icon: Icon(
                            _isAtGedungSate ? Icons.school : Icons.museum,
                            size: 14,
                          ),
                          label: Text(
                            _isAtGedungSate ? "Lihat Telyu" : "Lihat Wisata",
                            style: const TextStyle(fontSize: 12),
                          ),
                        ),
                      ],
                    ),
                  ],
                ),
              ),
            ),
          ),
        ],
      ),
      // Floating Action Button to transition between locations
      floatingActionButton: FloatingActionButton.extended(
        onPressed: _toggleLocation,
        icon: AnimatedRotation(
          duration: const Duration(milliseconds: 500),
          turns: _isAtGedungSate ? 0.5 : 0.0,
          child: Icon(_isAtGedungSate ? Icons.arrow_back : Icons.explore),
        ),
        label: Text(_isAtGedungSate ? "Ke Telkom Univ" : "Jelajah Wisata"),
        backgroundColor: _isAtGedungSate ? Colors.teal[600] : theme.colorScheme.primary,
        foregroundColor: Colors.white,
        elevation: 6,
      ),
    );
  }
}

// Custom widget to draw the pulsing circle animation under the markers
class _PulseCircle extends StatefulWidget {
  final Color color;
  const _PulseCircle({required this.color});

  @override
  State<_PulseCircle> createState() => _PulseCircleState();
}

class _PulseCircleState extends State<_PulseCircle> with SingleTickerProviderStateMixin {
  late AnimationController _animController;
  late Animation<double> _scaleAnimation;
  late Animation<double> _opacityAnimation;

  @override
  void initState() {
    super.initState();
    _animController = AnimationController(
      vsync: this,
      duration: const Duration(seconds: 2),
    )..repeat();
    
    _scaleAnimation = Tween<double>(begin: 0.8, end: 2.2).animate(
      CurvedAnimation(parent: _animController, curve: Curves.easeOut),
    );
    _opacityAnimation = Tween<double>(begin: 0.6, end: 0.0).animate(
      CurvedAnimation(parent: _animController, curve: Curves.easeOut),
    );
  }

  @override
  void dispose() {
    _animController.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return AnimatedBuilder(
      animation: _animController,
      builder: (context, child) {
        return Transform.scale(
          scale: _scaleAnimation.value,
          child: Opacity(
            opacity: _opacityAnimation.value,
            child: Container(
              width: 32,
              height: 32,
              decoration: BoxDecoration(
                color: widget.color.withOpacity(0.4),
                shape: BoxShape.circle,
              ),
            ),
          ),
        );
      },
    );
  }
}
