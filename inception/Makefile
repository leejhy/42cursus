VOLUME_DIR				:= $(HOME)/data/volumes
MARIADB_VOLUME_DIR		:= $(VOLUME_DIR)/mariadb
WORDPRESS_VOLUME_DIR	:= $(VOLUME_DIR)/wordpress
COMPOSE_FILE		    := srcs/docker-compose.yml

export VOLUME_DIR

all: 
	@mkdir -p $(MARIADB_VOLUME_DIR) $(WORDPRESS_VOLUME_DIR)
	DOCKER_BUILDKIT=1 docker-compose -f $(COMPOSE_FILE) up --build -d

clean:
	docker-compose -f $(COMPOSE_FILE) down 

fclean:
	docker-compose -f $(COMPOSE_FILE) down --rmi all --volumes --remove-orphans
	docker system prune --all --volumes --force
	rm -rf $(VOLUME_DIR)

ps logs images top:
	docker compose -f $(COMPOSE_FILE) $@

network :
	docker network ls

re:
	make fclean
	make all

.PHONY: ps logs images top 
.PHONY: all clean fclean re
