
#include <pebble.h>
#define KEY 58

static Window *s_main_window, *s_cat_window, *s_number_window, *s_list_window;
static StatusBarLayer *s_status_bar;
static ActionBarLayer *s_action_bar, *s_price_action_bar;
static TextLayer *s_price_layer, *pris_layer;
static GBitmap *s_up_bitmap, *s_down_bitmap, *s_check_bitmap, *s_price_up_bitmap, *s_price_down_bitmap, *s_price_check_bitmap;

static uint32_t price_int;
//declare menu
static MenuLayer *s_menu_layer, *list_layer;

char* price;
const char *cats[] = {
    "Bil",
    "Gåva",
    "Hemglädje",
    "Hälsa",
    "Livsnjutning",
    "Mat",
    "Musik",
    "Resor",
    "Skola"};

typedef struct {
  const char* category;
  uint16_t my_price;
} Expense;

uint8_t expense_size = 0;
uint8_t expense_row_size = 0;
Expense expense_arr[6];

char *itoa(int num)
{
  static char buff[20] = {};
  int i = 0, temp_num = num, length = 0;
  char *string = buff;
  if (num >= 0)
  {
    // count how many characters in the number
    while (temp_num)
    {
      temp_num /= 10;
      length++;
    }
    // assign the number to the buffer starting at the end of the
    // number and going to the begining since we are doing the
    // integer to character conversion on the last number in the
    // sequence
    for (i = 0; i < length; i++)
    {
      buff[(length - 1) - i] = '0' + (num % 10);
      num /= 10;
    }
    buff[i] = '\0'; // can't forget the null byte to properly end our string
  }
  else
    return "Unsupported Number";
  return string;
}

/****************************Draw Menu Layer****************************************/

static uint16_t get_num_rows_callback(MenuLayer *menu_layer,
                                      uint16_t section_price_int, void *context)
{
  const uint16_t num_rows = sizeof(cats) / sizeof(cats[0]);
  return num_rows;
}

static void draw_row_callback(GContext *ctx, const Layer *cell_layer,
                              MenuIndex *cell_price_int, void *context)
{
  int i = (int)cell_price_int->row;
  // Draw this row's price_int
  menu_cell_basic_draw(ctx, cell_layer, cats[i], NULL, NULL);
}

static int16_t get_cell_height_callback(struct MenuLayer *menu_layer,
                                        MenuIndex *cell_price_int, void *context)
{
  const int16_t cell_height = 30;
  return cell_height;
}

static void select_callback(struct MenuLayer *menu_layer,
                            MenuIndex *cell_price_int, void *context)
{
  // Do something in response to the button press
  window_stack_push(s_number_window, true);
}

/**********************************New LIST *****************************************************************/
static uint16_t list_get_num_rows_callback(MenuLayer *menu_layer,
                                      uint16_t section_index, void *context)
{
  const uint16_t num_rows = expense_row_size;
  return num_rows;
}

static void list_draw_row_callback(GContext *ctx, const Layer *cell_layer,
                              MenuIndex *cell_index, void *context)
{
  int i = (int)cell_index->row;
  // Draw this row's index
  menu_cell_basic_draw(ctx, cell_layer, expense_arr[i].category, itoa(expense_arr[i].my_price), NULL);
}

static int16_t list_get_cell_height_callback(struct MenuLayer *menu_layer,
                                        MenuIndex *cell_index, void *context)
{
  const int16_t cell_height = 50;
  return cell_height;
}

static void list_select_callback(struct MenuLayer *menu_layer,
                            MenuIndex *cell_index, void *context)
{
  // Do something in response to the button press
}

/**************************Click Config******************************************/
static void action_bar_add_handler(ClickRecognizerRef recognizer, void *context)
{
  window_stack_push(s_cat_window, true);
}

static void action_bar_list_handler(ClickRecognizerRef recognizer, void *context)
{
  window_stack_push(s_list_window, true);
}

static void action_bar_click_config_provider(void *context)
{
  // single click / repeat-on-hold config:
  window_single_click_subscribe(BUTTON_ID_UP, action_bar_list_handler);
  window_single_click_subscribe(BUTTON_ID_SELECT, action_bar_add_handler);
}

static void main_window_load(Window *window)
{
  s_status_bar = status_bar_layer_create();
  status_bar_layer_set_colors(s_status_bar, GColorBlack, GColorWhite);

  // Load icon bitmaps
  s_up_bitmap = gbitmap_create_with_resource(RESOURCE_ID_UP_ICON);
  //s_down_bitmap = gbitmap_create_with_resource(RESOURCE_ID_DOWN_ICON);
  s_check_bitmap = gbitmap_create_with_resource(RESOURCE_ID_CHECK_ICON);

  // Create ActionBarLayer
  s_action_bar = action_bar_layer_create();
  action_bar_layer_set_click_config_provider(s_action_bar, (ClickConfigProvider)action_bar_click_config_provider);

  // Set the icons
  action_bar_layer_set_icon(s_action_bar, BUTTON_ID_UP, s_up_bitmap);
  //action_bar_layer_set_icon(s_action_bar, BUTTON_ID_DOWN, s_down_bitmap);
  action_bar_layer_set_icon(s_action_bar, BUTTON_ID_SELECT, s_check_bitmap);

  // Add to Window
  action_bar_layer_add_to_window(s_action_bar, window);

  layer_add_child(window_get_root_layer(s_main_window), status_bar_layer_get_layer(s_status_bar));
}

static void main_window_unload(Window *window)
{
  status_bar_layer_destroy(s_status_bar);
  // Destroy the ActionBarLayer
  action_bar_layer_destroy(s_action_bar);

  // Destroy the icon GBitmaps
  gbitmap_destroy(s_up_bitmap);
  gbitmap_destroy(s_down_bitmap);
  gbitmap_destroy(s_check_bitmap);
}



static void cat_window_load(Window *window)
{
  Layer *window_layer = window_get_root_layer(s_cat_window);
  GRect bounds = layer_get_bounds(window_layer);

  //create menu layer
  s_menu_layer = menu_layer_create(bounds);
  // Let it receive click events
  menu_layer_set_click_config_onto_window(s_menu_layer, s_cat_window);

  // Set the callbacks for behavior and rendering
  menu_layer_set_callbacks(s_menu_layer, NULL, (MenuLayerCallbacks){
                                                   .get_num_rows = get_num_rows_callback,
                                                   .draw_row = draw_row_callback,
                                                   .get_cell_height = get_cell_height_callback,
                                                   .select_click = select_callback,
                                               });

  // Add the layers to the window
  layer_add_child(window_get_root_layer(s_cat_window), menu_layer_get_layer(s_menu_layer));
}

static void cat_window_unload(Window *window)
{
  menu_layer_destroy(s_menu_layer);
}


static void price_inc_handler(ClickRecognizerRef recognizer, void *context)
{
  price = itoa(++price_int);
  text_layer_set_text(s_price_layer, price);
}

static void price_dec_handler(ClickRecognizerRef recognizer, void *context)
{
  if(price_int > 1){
    price = itoa(--price_int);
    text_layer_set_text(s_price_layer, price);
  }
  else if(price_int == 1){
    price_int--;
    price = "0";
    text_layer_set_text(s_price_layer, price);
  }
}

static void price_add_handler(ClickRecognizerRef recognizer, void *context)
{
  MenuIndex m = menu_layer_get_selected_index(s_menu_layer);
  int t = m.row;
  Expense e = {cats[t], price_int};
  expense_arr[expense_size++] = e;
  if(expense_size > 5)  expense_size = 0;
  else  expense_row_size++;
  window_stack_pop(false);
  window_stack_pop(false);
  window_stack_push(s_list_window, true);

}

static void price_click_config_provider(void *context)
{
  // single click / repeat-on-hold config:
  //window_single_click_subscribe(BUTTON_ID_UP, price_inc_handler);
  window_single_click_subscribe(BUTTON_ID_SELECT, price_add_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_UP, 30, price_inc_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_DOWN, 30, price_dec_handler);
}

static void number_window_load(Window *window){
  s_price_layer = text_layer_create(GRect(26, 62, 80, 46));
  pris_layer = text_layer_create(GRect(28, 20, 80, 40));
  //MenuIndex m = menu_layer_get_selected_price_int(s_menu_layer);
  //price_int = m.row;
  price_int = 00;
  price = "00";

  text_layer_set_text_color(pris_layer, GColorBlack);
  text_layer_set_font(pris_layer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
  text_layer_set_background_color(pris_layer, GColorWhite);
  text_layer_set_text_alignment(pris_layer, GTextAlignmentCenter);
  text_layer_set_text(pris_layer, "Pris?");

  text_layer_set_text_color(s_price_layer, GColorWhite);
  text_layer_set_font(s_price_layer, fonts_get_system_font(FONT_KEY_LECO_38_BOLD_NUMBERS));
  text_layer_set_background_color(s_price_layer, GColorBlack);
  text_layer_set_overflow_mode(s_price_layer, GTextOverflowModeWordWrap);
  text_layer_set_text_alignment(s_price_layer, GTextAlignmentCenter);
  text_layer_set_text(s_price_layer, price);

  layer_add_child(window_get_root_layer(s_number_window), text_layer_get_layer(s_price_layer));
  layer_add_child(window_get_root_layer(s_number_window), text_layer_get_layer(pris_layer));

  // Load icon bitmaps
  s_price_up_bitmap = gbitmap_create_with_resource(RESOURCE_ID_UPA_ICON);
  s_price_down_bitmap = gbitmap_create_with_resource(RESOURCE_ID_DOWNA_ICON);
  s_price_check_bitmap = gbitmap_create_with_resource(RESOURCE_ID_CHECK_ICON);

  // Create ActionBarLayer
  s_price_action_bar = action_bar_layer_create();
  action_bar_layer_set_click_config_provider(s_price_action_bar, (ClickConfigProvider)price_click_config_provider);

  // Set the icons
  action_bar_layer_set_icon(s_price_action_bar, BUTTON_ID_UP, s_price_up_bitmap);
  action_bar_layer_set_icon(s_price_action_bar, BUTTON_ID_DOWN, s_price_down_bitmap);
  action_bar_layer_set_icon(s_price_action_bar, BUTTON_ID_SELECT, s_price_check_bitmap);

  // Add to Window
  action_bar_layer_add_to_window(s_price_action_bar, window);
}

static void number_window_unload(Window *window){
  text_layer_destroy(s_price_layer);
  text_layer_destroy(pris_layer);
  action_bar_layer_destroy(s_price_action_bar);
}



static void list_window_load(Window *window)
{
  Layer *window_layer = window_get_root_layer(s_list_window);
  GRect bounds = layer_get_bounds(window_layer);

  //create menu layer
  list_layer = menu_layer_create(bounds);
  // Let it receive click events
  menu_layer_set_click_config_onto_window(list_layer, s_list_window);

  // Set the callbacks for behavior and rendering
  menu_layer_set_callbacks(list_layer, NULL, (MenuLayerCallbacks){
                                                   .get_num_rows = list_get_num_rows_callback,
                                                   .draw_row = list_draw_row_callback,
                                                   .get_cell_height = list_get_cell_height_callback,
                                                   .select_click = list_select_callback,
                                               });

  // Add the layers to the window
  layer_add_child(window_get_root_layer(s_list_window), menu_layer_get_layer(list_layer));
}

static void list_window_unload(Window *window){
  menu_layer_destroy(list_layer);
  persist_write_data(KEY, expense_arr, (size_t)sizeof(expense_arr));
}



static void init(void)
{
  if(persist_exists(KEY)){
    persist_read_data(KEY, expense_arr, sizeof(expense_arr));
    expense_row_size = persist_read_int(12);
    expense_size = persist_read_int(15);
  }
  // Create a window and get information about the window
  s_cat_window = window_create();
  window_set_window_handlers(s_cat_window, (WindowHandlers){
                                               .load = cat_window_load,
                                               .unload = cat_window_unload,
                                           });

  s_main_window = window_create();
  window_set_window_handlers(s_main_window, (WindowHandlers){
                                                .load = main_window_load,
                                                .unload = main_window_unload,
                                            });

  s_number_window = window_create();
  window_set_window_handlers(s_number_window, (WindowHandlers){
    .load = number_window_load,
    .unload = number_window_unload,
  });
  
  s_list_window = window_create();
  window_set_window_handlers(s_list_window, (WindowHandlers){
    .load = list_window_load,
    .unload = list_window_unload,
  });

  // Push the window, setting the window animation to 'true'
  window_stack_push(s_main_window, true);

  // App Logging!
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Just pushed a window!");
}

static void deinit(void)
{
  // Destroy the window
  persist_write_data(KEY, expense_arr, sizeof(expense_arr));
  persist_write_int(12, expense_row_size);
  persist_write_int(15, expense_size);
  window_destroy(s_cat_window);
}

int main(void)
{
  init();
  app_event_loop();
  deinit();
}
