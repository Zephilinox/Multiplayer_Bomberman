.PHONY: clean All

All:
	@echo "----------Building project:[ Multiplayer_Bomberman - Debug ]----------"
	@$(MAKE) -f  "Multiplayer_Bomberman.mk"
clean:
	@echo "----------Cleaning project:[ Multiplayer_Bomberman - Debug ]----------"
	@$(MAKE) -f  "Multiplayer_Bomberman.mk" clean
