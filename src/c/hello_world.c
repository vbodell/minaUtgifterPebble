
#include <pebble.h>

static Window *s_window, *s_cat_window, *s_price_window;
static StatusBarLayer *s_status_bar;

//declare menu
static MenuLayer *s_menu_layer;

const char *cats[] = {
  "Bil",
  "Gåva",
  "Hemglädje",
  "Hälsa",
  "Livsnjutning",
  "Mat",
  "Musik",
  "Resor",
  "Skola"
};

static uint16_t get_num_rows_callback(MenuLayer *menu_layer, 
                                      uint16_t section_index, void *context) {
  const uint16_t num_rows = sizeof(cats)/sizeof(cats[0]);
  return num_rows;
}

static void draw_row_callback(GContext *ctx, const Layer *cell_layer, 
                                        MenuIndex *cell_index, void *context) {
  int i = (int)cell_index->row;
  // Draw this row's index
  menu_cell_basic_draw(ctx, cell_layer, cats[i], NULL, NULL);
}

static int16_t get_cell_height_callback(struct MenuLayer *menu_layer, 
                                        MenuIndex *cell_index, void *context) {
  const int16_t cell_height = 30;
  return cell_height;
}

static void select_callback(struct MenuLayer *menu_layer, 
                                        MenuIndex *cell_index, void *context) {
  // Do something in response to the button press
}

static void cat_window_load(Window *window){
  Layer *window_layer = window_get_root_layer(s_cat_window);
  GRect bounds = layer_get_bounds(window_layer);
  
  
  //create status bar
  s_status_bar = status_bar_layer_create();
  status_bar_layer_set_colors(s_status_bar, GColorBlack, GColorWhite);
  
  
  //create menu layer
  s_menu_layer = menu_layer_create(bounds);
  // Let it receive click events
  menu_layer_set_click_config_onto_window(s_menu_layer, s_cat_window);

  // Set the callbacks for behavior and rendering
  menu_layer_set_callbacks(s_menu_layer, NULL, (MenuLayerCallbacks) {
      .get_num_rows = get_num_rows_callback,
      .draw_row = draw_row_callback,
      .get_cell_height = get_cell_height_callback,
      .select_click = select_callback,
  });
  
  // Add the layers to the window
  layer_add_child(window_get_root_layer(s_cat_window), menu_layer_get_layer(s_menu_layer));
  layer_add_child(window_get_root_layer(s_cat_window), status_bar_layer_get_layer(s_status_bar));
  
}

static void cat_window_unload(Window *window){
  menu_layer_destroy(s_menu_layer);
  status_bar_layer_destroy(s_status_bar);
}

static void init(void) {
	// Create a window and get information about the window
	s_cat_window = window_create();
  window_set_window_handlers(s_cat_window, (WindowHandlers){
    .load = cat_window_load,
    .unload = cat_window_unload,
  });
    
	// Push the window, setting the window animation to 'true'
	window_stack_push(s_cat_window, true);
	
	// App Logging!
	APP_LOG(APP_LOG_LEVEL_DEBUG, "Just pushed a window!");
}

static void deinit(void) {
	
	// Destroy the window
	window_destroy(s_cat_window);
}

int main(void) {
	init();
	app_event_loop();
	deinit();
}

