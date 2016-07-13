#define CREATE_ROOM_SUCCESS "1440"
#define CREATE_ROOM_FAIL "1441"
#define JOIN_ROOM_FAIL "2091"
#define JOIN_ROOM_SUCCESS "2090"
#define ROOM_CLOSED "116"
#define LEAVE_ROOM_SUCCESS "1120"
#define RETURN_USER_LIST "108"
#define SQL_OPEN_EXCEPTION 1.01
#define DB_NAME "triviadb.db"
#define ANSWER_ARRAY_SIZE 4
#define FAILED_SIGNIN_WRONG_DETAILS "1021"
#define FAILED_SIGNIN_USER_CONNECTED "1022"
#define USER_EXISTS_COMMAND "SELECT username FROM t_users WHERE username = '" 
#define FINISH_SQL_COMMAND	" ;"
#define INSERT_NEW_GAME_COMMAND "INSERT INTO t_games(status,start_time) values(0,datetime('now');"
#define FIND_GAME_ID_COMMAND "SELECT game_id FROM t_games;"
//by the way, i could not have a parameter named "password" since its a used command in sqlite3
#define INSERT_NEW_USER_COMMAND "INSERT INTO t_users(username,pass,email) values('"
#define FINISH_SQL_COMMAND_2 " );"
#define CHECK_LOGIN_COMMAND "SELECT username FROM t_users WHERE username ='"
#define INIT_QUESTIONS_COMMAND "SELECT * FROM t_questions;"
#define INIT_QUESTIONS_SIZE 30
#define QUESTION_DATA_LINES 6
#define GAME_UPDATE_COMMAND "UPDATE t_games SET status = 1 WHERE game_id = "
#define NEW_ANSWER_COMMAND "INSERT INTO t_players_answers(game_id,username,question_id,player_answer,is_correct,answer_time) values("
#define BEST_SCORES_COMMAND "SELECT * FROM t_players_answers;"
#define COUNT_ANSWERS_COMMAND "SELECT COUNT(*) FROM t_players_answers"
#define TURN_TIME_SCORE 60
#define SCOREBOARD_ROWS 10
#define FINISHED_GAME_CODE "121"
#define SPACE "##"
#define CORRECT_ANSWER "120"